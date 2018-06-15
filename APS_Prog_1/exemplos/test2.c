#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
 



void* memory_allocada(size_t item_size, size_t n_item)
{
  size_t *x = calloc(1, sizeof(size_t)*2 + n_item * item_size);
  x[0] = item_size;
  x[1] = n_item;
  return x + 2;
}
 



void* memory_extended(void *m, size_t new_n)
{
  size_t *x = (size_t*)m - 2;
  x = realloc(x, sizeof(size_t) * 2 + *x * new_n);
  if (new_n > x[1])
    memset((char*)(x + 2) + x[0] * x[1], 0, x[0] * (new_n - x[1]));
  x[1] = new_n;
  return x + 2;
}
 



inline void _clear(void *m)
{
  size_t *x = (size_t*)m - 2;
  memset(m, 0, x[0] * x[1]);
}
 


#define _new(type, n) memory_allocada(sizeof(type), n)
#define _del(m)   { free((size_t*)(m) - 2); m = 0; }
#define _len(m)   *((size_t*)m - 1)
#define _setsize(m, n)  m = memory_extended(m, n)
#define _extend(m)  m = memory_extended(m, _len(m) * 2)
 
 



typedef uint8_t byte;
typedef uint16_t ushort;
 



#define M_CLR 256 /* limpa tabela de criação */
#define M_EOD 257 /* marcador de fim de dados */
#define M_NEW 258 /* novo índice de código */
 




typedef struct {
  ushort next[256];
} lzw_enc_t;
 




typedef struct {
  ushort prev, back;
  byte c;
} lzw_dec_t;
 




byte* encode(byte *in, int max_bits)
{
  int len = _len(in), bits = 9, next_shift = 512;
  ushort code, c, nc, next_code = M_NEW;
  lzw_enc_t *d = _new(lzw_enc_t, 512);
 
  if (max_bits > 15) max_bits = 15;
  if (max_bits < 9 ) max_bits = 12;
 
  byte *out = _new(ushort, 4);
  int out_len = 0, o_bits = 0;
  uint32_t tmp = 0;
 
  inline void write_bits(ushort x) {
    tmp = (tmp << bits) | x;
    o_bits += bits;
    if (_len(out) <= out_len) _extend(out);
    while (o_bits >= 8) {
      o_bits -= 8;
      out[out_len++] = tmp >> o_bits;
      tmp &= (1 << o_bits) - 1;
    }
  }
 
  
  for (code = *(in++); --len; ) {
    c = *(in++);
    if ((nc = d[code].next[c]))
      code = nc;
    else {
      write_bits(code);
      nc = d[code].next[c] = next_code++;
      code = c;
    }
 
    /* o próximo código novo seria muito longo para a tabela atual */
    if (next_code == next_shift) {
      /* ou redefinir a tabela de volta para 9 bits */
      if (++bits > max_bits) {
        /* marcador claro da tabela deve ocorrer antes da redefinição de bit*/
        
        write_bits(M_CLR);
 
        bits = 9;
        next_shift = 512;
        next_code = M_NEW;
        _clear(d);
      } else  /* ou extende o demonio da tabela*/
        _setsize(d, next_shift *= 2);
    }
  }
 
  write_bits(code);
  write_bits(M_EOD);
  if (tmp) write_bits(tmp);
 
  _del(d);
 
  _setsize(out, out_len);
  return out;
}
 






int main()
{
  int i, file = open("Teste1_Texto.txt", O_RDONLY);
 
  if (file == -1) {
    fprintf(stderr, "Naum pode abrir os file lesk rsrsr\n");
    return 1;
  };
 
  struct stat st;
  fstat(file, &st);
 
  byte *ENTRADA = _new(char, st.st_size);
  read(file, ENTRADA, st.st_size);
  _setsize(ENTRADA, st.st_size);
  close(file);
 
  printf("Entrada size:   %d\n", _len(ENTRADA));
 
  byte *enc = encode(ENTRADA, 9); // CHAMA FUNCAO PRA ENCODAR O DADO
  printf("encoded size: %d\n", _len(enc));
 
  return 0;
}