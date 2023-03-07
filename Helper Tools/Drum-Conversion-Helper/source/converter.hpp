#pragma once

#include <vector>

#include "note.hpp"

void BanksInit();
bool IsBankValid(int bankIndex);
Note GetConverted(int n3D_bankIndex, Note n64_note);
