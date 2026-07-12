#include "sort.h"
#include <stdlib.h>

/* Tausche zwei Zahlen */
void swap(uint32_t* a, uint32_t* b) {
  uint32_t temp = *a;
  *a = *b;
  *b = temp;
}

/* Bubble Sort mit Early Exit */
void bubbleSort(uint32_t* array, uint32_t len) {
  if (len <= 1) {
    return;
  }
  
  /* Gehe durch das Array */
  for (uint32_t i = 0; i < len - 1; i++) {
    uint32_t swapped = 0;
    
    /* Vergleiche benachbarte Elemente */
    for (uint32_t j = 0; j < len - 1 - i; j++) {
      if (array[j] > array[j + 1]) {
        swap(&array[j], &array[j + 1]);
        swapped = 1;
      }
    }
    
    /* Wenn nichts getauscht wurde, ist das Array fertig sortiert */
    if (swapped == 0) {
      break;
    }
  }
}

/* Hilfsfunktion für QuickSort */
void quickSortHelper(uint32_t* array, uint32_t low, uint32_t high) {
  if (low >= high) {
    return;
  }
  
  /* Pivot ist das letzte Element */
  uint32_t pivot = array[high];
  uint32_t i = low;
  
  /* Partitionierung: kleine Werte links, große rechts */
  for (uint32_t j = low; j < high; j++) {
    if (array[j] <= pivot) {
      swap(&array[i], &array[j]);
      i++;
    }
  }
  
  /* Setze Pivot an die richtige Position */
  swap(&array[i], &array[high]);
  
  /* Sortiere linke und rechte Seite rekursiv */
  if (i > 0) {
    quickSortHelper(array, low, i - 1);
  }
  quickSortHelper(array, i + 1, high);
}

/* QuickSort */
void quickSort(uint32_t* array, uint32_t len) {
  if (len <= 1) {
    return;
  }
  
  quickSortHelper(array, 0, len - 1);
}

/* Hilfsfunktion für QuickSort mit zufälligem Pivot */
void quickSortRandomHelper(uint32_t* array, uint32_t low, uint32_t high) {
  if (low >= high) {
    return;
  }
  
  /* Wähle zufälliges Element als Pivot */
  uint32_t random_index = low + (rand() % (high - low + 1));
  swap(&array[random_index], &array[high]);
  
  /* Pivot ist jetzt das letzte Element */
  uint32_t pivot = array[high];
  uint32_t i = low;
  
  /* Partitionierung */
  for (uint32_t j = low; j < high; j++) {
    if (array[j] <= pivot) {
      swap(&array[i], &array[j]);
      i++;
    }
  }
  
  /* Setze Pivot an die richtige Position */
  swap(&array[i], &array[high]);
  
  /* Sortiere linke und rechte Seite rekursiv */
  if (i > 0) {
    quickSortRandomHelper(array, low, i - 1);
  }
  quickSortRandomHelper(array, i + 1, high);
}

/* QuickSort mit zufälligem Pivot */
void quickSortRandom(uint32_t* array, uint32_t len) {
  if (len <= 1) {
    return;
  }
  
  quickSortRandomHelper(array, 0, len - 1);
}