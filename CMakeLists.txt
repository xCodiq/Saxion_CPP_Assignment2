cmake_minimum_required(VERSION 3.20)
project(Assignment2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Assignment2 main.cpp util/textfile/TextfileUtil.cpp util/textfile/TextfileUtil.h transaction/Transaction.cpp transaction/Transaction.h util/validation/Validator.cpp util/validation/Validator.h program/Program.cpp program/Program.h)
