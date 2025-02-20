/*
 * CS106L Assignment 2: Marriage Pact
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 */

#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>

std::string kYourName = "Vdack Chen"; // Don't forget to change this!

/**
 * Takes in a file name and returns a set containing all of the applicant names as a set.
 *
 * @param filename  The name of the file to read.
 *                  Each line of the file will be a single applicant's name.
 * @returns         A set of all applicant names read from the file.
 *
 * @remark Feel free to change the return type of this function (and the function
 * below it) to use a `std::unordered_set` instead. If you do so, make sure
 * to also change the corresponding functions in `utils.h`.
 */
std::set<std::string> get_applicants(std::string filename) {
  std::ifstream fnames(filename);
  std::set<std::string> names; 
  while(!fnames.eof()){
    std::string name;
    std::getline(fnames, name);
    if (name.size() == 0){
      continue;
    }
    names.insert(name);
  }
  fnames.close();
  return names;
}

bool shareInitials(const std::string& name1, const std::string& name2) {
  if (name1[0] != name2[0]) {
    return false;
  }
  int posi1 = name1.find(' ');
  int posi2 = name2.find(' ');
  if (name1[posi1 + 1] != name2[posi2 + 1]){
    return false;
  }
  return true;
}

/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name.
 *
 * @param name      The returned queue of names should have the same initials as this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */
std::queue<const std::string*> find_matches(std::string name, std::set<std::string>& students) {
  std::queue<const std::string*> matched_names;
  std::cout<<name<<std::endl;
  int length = name.size();
  for (const std::string& candidate_name: students) {
    if (shareInitials(candidate_name, name)) {
      matched_names.push(&candidate_name);
    }
  }
  return matched_names;
}



/**
 * Takes in a queue of pointers to possible matches and determines the one true match!
 *
 * You can implement this function however you'd like, but try to do something a bit
 * more complicated than a simple `pop()`.
 *
 * @param matches The queue of possible matches.
 * @return        Your magical one true love.
 *                Will return "NO MATCHES FOUND." if `matches` is empty.
 */
std::string get_match(std::queue<const std::string*>& matches) {
  if (matches.empty()) {
    return "NO MATCHES FOUND.";
  }
  return *matches.front();
}

/* #### Please don't remove this line! #### */
#include "autograder/utils.hpp"
