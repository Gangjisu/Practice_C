#ifndef _SCORE_H_//한번만 실행하기위한 일종의 조건문
#define _SCORE_H_

//#pragma once 한번만 실행

//함수의 선언,전역변수 선언


int GetScores(double score_Arr[],int arr_Size);

double GetAverageScore(const double score_Arr[],int arr_Size);

double GetMaxScore(const double score_Arr[],int arr_Size);

double GetMinScore(const double score_Arr[],int arr_Size);

#endif