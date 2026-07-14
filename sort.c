#include "sort.h"
#include <stdlib.h>
#include <stdbool.h>

/* Tauscht zwei Elemente */
static void swap(uint32_t* a, uint32_t* b) {
  uint32_t temp = *a;
  *a = *b;
  *b = temp;
}


/* Bubble Sort mit Early Exit */
void bubbleSort(uint32_t* array, uint32_t len) {

  if (len <= 1) {
    return;
  }

  for (uint32_t i = len - 1; i >= 1; i--) {
    bool is_sorted = true;

    for (uint32_t j = 1; j <= i; j++) {
      if (array[j - 1] > array[j]) {
        swap(&array[j], &array[j - 1]);
        is_sorted = false;
      }
    }
    /* Array war bereits sortiert */
    if (is_sorted) {
      return;
    }
  }
}


/*
 * Partition wie in der Vorlesung:
 * Pivot ist das erste Element.
 *
 * Alle Elemente kleiner als Pivot
 * kommen nach links.
 */
static uint32_t partition(uint32_t* array, uint32_t low, uint32_t high) {
  uint32_t pivot = array[low];
  uint32_t m = low;
  for (uint32_t k = low + 1; k <= high; k++) {
    if (array[k] < pivot) {
      m++;
      swap(&array[k], &array[m]);
    }
  }

  /* Pivot an die richtige Position setzen */
  swap(&array[low], &array[m]);
  return m;
}


/* Hilfsfunktion für QuickSort */
static void quickSortHelper(uint32_t* array, uint32_t low, uint32_t high) {
  if (low < high) {
    uint32_t pivotIndex = partition(array, low, high);
    if (pivotIndex > 0) {
      quickSortHelper(array, low, pivotIndex - 1);
    }
    quickSortHelper(array, pivotIndex + 1, high);
  }
}


/* QuickSort */
void quickSort(uint32_t* array, uint32_t len) {
  if (len <= 1) {
    return;
  }
  quickSortHelper(array, 0, len - 1);
}


/* Hilfsfunktion für QuickSortRandom */
static void quickSortRandomHelper(uint32_t* array, uint32_t low, uint32_t high) {
  if (low < high) {
    /*
     * Zufälliges Pivot auswählen
     * und an Position low verschieben.
     */
    uint32_t randomIndex =
        low + (rand() % (high - low + 1));
    swap(&array[low], &array[randomIndex]);

    /*
     * Danach normale Partition
     * aus der Vorlesung verwenden.
     */
    uint32_t pivotIndex = partition(array, low, high);
    if (pivotIndex > 0) {
      quickSortRandomHelper(array, low, pivotIndex - 1);
    }
    quickSortRandomHelper(array, pivotIndex + 1, high);
  }
}


/* QuickSort mit zufälligem Pivot */
void quickSortRandom(uint32_t* array, uint32_t len) {
  if (len <= 1) {
    return;
  }
  quickSortRandomHelper(array, 0, len - 1);
}