// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), amount(0), head(nullptr), tail(nullptr) {}

void Train::addCage(bool light) {
  if (!head) {
    Cage* newCage = new Cage;
    newCage->light = light;
    head = newCage;
    tail = newCage;
  } else {
    Cage* newCage = new Cage;
    newCage->light = light;
    tail->next = newCage;
    newCage->prev = tail;
    tail = newCage;
  }
  tail->next = head;
  head->prev = tail;
}

int Train::getLength() {
  Cage* cage = head;
  cage->light = true;
  while (true) {
    cage = cage->next;
    amount++;
    if (cage->light) {
      cage->light = false;
      for (int i = 0; i < amount; i++) {
        cage = cage->prev;
      }
      countOp += amount * 2;
      if (!cage->light) {
        return amount;
      }
      amount = 0;
    }
  }
}

int Train::getOpCount() {
  return countOp;
}
