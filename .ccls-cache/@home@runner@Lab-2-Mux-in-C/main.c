#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// BEGIN STRINGBUILDER IMPLEMENTATION
// Don't edit the stringbuilder implementation.

// This code is a very rudimentary stringbuilder-like implementation
// To create a new stringbuilder, use the following line of code
//
//     stringbuilder sb = new_sb();
//
// If you want to append a character to the stringbuilder, use the
// following line of code. Replace whatever character you want to
// append where the 'a' is.
//
//     sb_append_char(sb, 'a');
//
// Though there are some other functions that might be useful to you,
// the driver code provided uses the functions, so there is no need
// to use them manually.

typedef struct {
  char** cars;
  size_t* len;
  size_t* alloc_size;
} stringbuilder;

stringbuilder new_sb() {
  stringbuilder sb;
  sb.cars = malloc(sizeof(char*));
  *sb.cars = malloc(8*sizeof(char));
  (*sb.cars)[0] = 0;
  sb.len = malloc(sizeof(size_t));
  *sb.len = 0;
  sb.alloc_size = malloc(sizeof(size_t));
  *sb.alloc_size = 8;
  return sb;
}

void sb_append(stringbuilder sb, char a) {
  int len = *sb.len;
  if (len >= (*sb.alloc_size)-1) {
    *sb.alloc_size = (*sb.alloc_size)*2;
    char* newcars = malloc((*sb.alloc_size)*sizeof(char));
    for (int i = 0; i < *sb.len; i++) {
      newcars[i] = (*sb.cars)[i];
    }
    free(*sb.cars);
    (*sb.cars) = newcars;
  }
  (*sb.cars)[len] = a;
  len++;
  (*sb.cars)[len] = 0;
  *sb.len = len;
}

void delete_sb(stringbuilder sb) {
  free(*sb.cars);
  free(sb.cars);
  free(sb.len);
  free(sb.alloc_size);
}

bool sb_is_equal(stringbuilder sb1, stringbuilder sb2) {
  if (*sb1.len != *sb2.len)
    return false;
  for (int i = 0; i < *sb1.len; i++) {
    if ((*sb1.cars)[i] != (*sb2.cars)[i])
      return false;
  }
  return true;
}

void print_sb(const stringbuilder sb) {
  printf("%s", *sb.cars);
}

// END STRINGBUILDER IMPLEMENTATION
// ============================================================

// Write your solutions to the tasks below

//Return the correct input according to the selector line.
//This is supposed to simulate a 1 var mux.
//s0 stands for the selector line.
//i0 and i1 stand for the input lines
// if s0 is 0 then the ouput should return whatever
//is in i0.
//**The test method will check one possible variation but make
//sure that the method will work with any variation of s0!
stringbuilder task_0(int s0, stringbuilder i0, stringbuilder i1) {
  stringbuilder sb = new_sb();
  if(s0 == 0)
    sb = i0;
  else
    sb = i1;
 
  return sb;
}

//Return the correct input according to the selector line.
//This is supposed to simulate a 2 var mux.
//s0 and s1 stands for the selector line.Can only be 1 or 0
//i0, i1, i2, i3 stand for the input lines.
//If s1 is 0 and s0 is 0 then the output should return
//whatever is in i0.
//**The test method will check one possible variation but
// make sure that the method will work with any variation of s1 and s0!
stringbuilder task_1(int s0, int s1,stringbuilder i0,stringbuilder i1,stringbuilder i2,stringbuilder i3) {
  stringbuilder sb= new_sb();
  
  if(s0 == 0 & s1 == 0)
    sb = i0;
  else if(s0 == 0 & s1 == 1)
    sb = i1;
  else if(s0 == 1 & s1 == 0)
    sb = i2;
  else if (s0 == 1 & s1 == 1)
    sb = i3;
  
  return sb;
}

// Testing
int main() {
  stringbuilder ii0= new_sb();
  stringbuilder ii1= new_sb();
  stringbuilder ii2= new_sb();
  stringbuilder ii3= new_sb();
  sb_append(ii0, '0');
  sb_append(ii0, '0');
  sb_append(ii0, '0');
  sb_append(ii0, '0');
  sb_append(ii1, '0');
  sb_append(ii1, '0');
  sb_append(ii1, '0');
  sb_append(ii1, '1');
  sb_append(ii2, '0');
  sb_append(ii2, '0');
  sb_append(ii2, '1');
  sb_append(ii2, '0');
  sb_append(ii3, '0');
  sb_append(ii3, '0');
  sb_append(ii3, '1');
  sb_append(ii3, '1');

  //testing
  stringbuilder t0 = task_0(0, ii0, ii1);
  printf("Testing task0 selecting input 0:\n");
  if(!sb_is_equal(t0,ii0)){
    printf("Failed\n");
    printf("Expected: ");
    print_sb(ii0);
    printf("\n");
  printf("Received: ");
  print_sb(t0);
  printf("\n");
  }
  else{
    printf("Passed\n\n");
  }
 
  stringbuilder t01 = task_0(1, ii0, ii1);
  printf("Testing task0 selecting input 1:\n");
  if(!sb_is_equal(t01,ii1)){
    printf("Failed\n");
    printf("Expected: ");
    print_sb(ii1);
    printf("\n");
  printf("Received: ");
  print_sb(t01);
  printf("\n");
  }
  else{
    printf("Passed\n\n");
  }
  printf("\n");
  stringbuilder t1 = task_1(0,0,ii0,ii1,ii2,ii3);
  printf("Testing task1 with input 00:\n");
  if(!sb_is_equal(t1,ii0)){
    printf("Failed\n");
    printf("Expected: ");
    print_sb(ii0);
    printf("\n");
    printf("Received: ");
  print_sb(t1);
  printf("\n");
  }
  else{
    printf("Passed");
  }

  stringbuilder t11 = task_1(0,1,ii0,ii1,ii2,ii3);
  printf("Testing task1 with input 01:\n");
  if(!sb_is_equal(t11,ii1)){
    printf("Failed\n");
    printf("Expected: ");
    print_sb(ii1);
    printf("\n");
    printf("Received: ");
  print_sb(t11);
  printf("\n");
  }
  else{
    printf("Passed");
  }

  stringbuilder t12 = task_1(1,0,ii0,ii1,ii2,ii3);
  printf("Testing task1 with input 10:\n");
  if(!sb_is_equal(t12,ii2)){
    printf("Failed\n");
    printf("Expected: ");
    print_sb(ii2);
    printf("\n");
    printf("Received: ");
  print_sb(t12);
  printf("\n");
  }
  else{
    printf("Passed");
  }

  stringbuilder t13 = task_1(1,1,ii0,ii1,ii2,ii3);
  printf("Testing task1 with input 11:\n");
  if(!sb_is_equal(t13,ii3)){
    printf("Failed\n");
    printf("Expected: ");
    print_sb(ii3);
    printf("\n");
    printf("Received: ");
  print_sb(t13);
  printf("\n");
  }
  else{
    printf("Passed");
  }
}
