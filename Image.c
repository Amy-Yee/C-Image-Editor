#include <stdio.h>
#include <assert.h>
#include "Image.h"

/* Return the image's width in pixels */
unsigned int ImageWidth(const IMAGE *image) {
  assert(image);
  return(image -> W);
}

/* Return the image's height in pixels */
unsigned int ImageHeight(const IMAGE *image) {
  assert(image);
  return(image -> H);
}

/* Get the R intensity of pixel (x, y) in image */
unsigned char GetPixelR(const IMAGE *image, unsigned int x,  unsigned int y) {
  assert(image);
  assert(x < (image -> W));
  assert(y < (image -> H));
  return image -> R[x + y * (image -> W)];
}

/* Get the G intensity of pixel (x, y) in image */
unsigned char GetPixelG(const IMAGE *image, unsigned int x,  unsigned int y) {
  assert(image);
  assert(x < (image -> W));
  assert(y < (image -> H));
  return image -> G[x + y * (image -> W)];
}

/* Get the B intensity of pixel (x, y) in image */
unsigned char GetPixelB(const IMAGE *image, unsigned int x,  unsigned int y) {
  assert(image);
  assert(x < (image -> W));
  assert(y < (image -> H));
  return image -> B[x + y * (image -> W)];
}

/* Set the R intensity of pixel (x, y) in image to r */
void SetPixelR(IMAGE *image, unsigned int x,  unsigned int y, unsigned char r) {
  assert(image);
  assert(x < (image -> W));
  assert(y < (image -> H));
  image -> R[x + y * (image -> W)] = r;
}

/* Set the G intensity of pixel (x, y) in image to g */
void SetPixelG(IMAGE *image, unsigned int x,  unsigned int y, unsigned char g) {
  assert(image);
  assert(x < (image -> W));
  assert(y < (image -> H));
  image -> G[x + y * (image -> W)] = g;
}

/* Set the B intensity of pixel (x, y) in image to b */
void SetPixelB(IMAGE *image, unsigned int x,  unsigned int y, unsigned char b) {
  assert(image);
  assert(x < (image -> W));
  assert(y < (image -> H));
  image -> B[x + y * (image -> W)] = b;
}

/* Allocate dynamic memory for the image structure and its R/G/B values */
/* Return the pointer to the image, or NULL in case of error */
IMAGE *CreateImage(unsigned int Width, unsigned int Height) {

  IMAGE *image = malloc(sizeof(IMAGE));

  if(!image) {
    free(image);
    return NULL;
  }

  if (image) {
    image -> R = malloc(Width * Height * sizeof(unsigned int));
    image -> G = malloc(Width * Height * sizeof(unsigned int));
    image -> B = malloc(Width * Height * sizeof(unsigned int));
  }

  return image;

}

/* Free the memory for the R/G/B values and IMAGE structure */
void DeleteImage(IMAGE *image) {
  assert (image);
  assert (image -> R);
  assert (image -> G);
  assert (image -> B);

  free(image -> R);
  image -> R = NULL;
  free(image -> G);
  image -> G = NULL;
  free(image -> B);
  image -> B = NULL;
  free (image);
  image = NULL;

}
