#pragma once
#ifndef __HEAD_H__
#define __HEAD_H__
#include <iostream>
#include <fstream>
using namespace std;

//cac ham sap xep



//
void taoMang(int*& array, int soLuongPhanTu);
int timSoLuongPhanTu(int i);
string timSize(int i);
void taoTenFileInput(string &fileName, string state, string duoiFile, int i);
void ghiXuongFile(string tenFile, int* array, int soLuongPhanTu);
void tienHanhSapXepVaGhiXuongFile(int* a, int soLuongPhanTu, ofstream& result, string state, string size); void xuLy(int* array, string state, int i, ofstream& result);
void sapXep(string state, ofstream& result);

#endif