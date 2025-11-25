#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sort.h"

uint32_t read_input(uint32_t** array) {
  // First number is number of elements
  uint32_t num_elements = 0;
  uint32_t buf1 = 0;
  char buf2 = '\0';
  
  if (scanf("%u", &num_elements) <= 0) {
    perror("scanf reading num_elements");
    *array = (uint32_t*) NULL;
    return 0;
  }
  
  *array = (uint32_t*) calloc(num_elements, sizeof(uint32_t));
  
  // eat everything until the next new line
  while(getchar() != '\n');
  
  for (uint32_t i = 0; i < num_elements; ++i) {
      buf1 = 0;
      
      while (true) {
        buf2 = (char) getchar();
        
        if (buf2 >= '0' && buf2 <= '9') {
          buf1 = buf1 * 10 + buf2 - '0';
        } else {
          break;
        }
      }
            
      (*array)[i] = buf1;
      
      if (buf2 == '\n' || buf2 == EOF) {
        return i + 1;
      }
  }
    
  return num_elements;
}

void write_output(const uint32_t* array, uint32_t length) {
  char endchar = ' ';
  for (uint32_t i = 0; i < length; ++i) {
    if (i >= length - 1)
      endchar = '\n';
    printf("%u%c", array[i], endchar);
  }
}

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  uint32_t* input_array;
  uint32_t num_elements = read_input(&input_array);
  
  if (num_elements <= 0) {
    fputs("Failed to read array", stderr);
    return -1;
  }
  
  uint32_t* input_copy = (uint32_t*) calloc(num_elements, sizeof(uint32_t));
  memcpy(input_copy, input_array, num_elements * sizeof(uint32_t));
  
  bubbleSort(input_copy, num_elements);
  
  write_output(input_copy, num_elements);
  
  memcpy(input_copy, input_array, num_elements * sizeof(uint32_t));
  
  quickSort(input_copy, num_elements);
  
  write_output(input_copy, num_elements);
  
  memcpy(input_copy, input_array, num_elements * sizeof(uint32_t));
  
  quickSortRandom(input_copy, num_elements);
  
  write_output(input_copy, num_elements);
  
  free(input_copy);
  input_copy = (uint32_t*) NULL;
  
  free(input_array);
  input_array = (uint32_t*) NULL;

  return 0;
}
