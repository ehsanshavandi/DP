#include <iostream>
#include <vector>

using namespace std;

vector<int> lis(const int* array, const size_t size) {
  vector<vector<int>> incSubSeq;
  for (size_t i = 0; i < size; ++i) {
    bool inserted = false;
    for (auto& subSeq : incSubSeq) {
      if (array[i] > subSeq.at(subSeq.size() - 1)) {
        subSeq.push_back(array[i]);
        inserted = true;
      }
    }
    if (!inserted) {
      vector<int> tmp;
      tmp.push_back(array[i]);
      incSubSeq.push_back(tmp);
    }
  }

  // TEST

  //    for (auto subSeq : incSubSeq) {
  //        cout << "subSeq " << subSeq[0] << ":[";
  //        for (auto elem : subSeq) {
  //            cout << elem << ", ";
  //        }
  //        cout << "]" << endl;
  //    }

  std::vector<int> largestVector;
  size_t maxSize = 0;

  for (const auto& vec : incSubSeq) {
    if (vec.size() > maxSize) {
      largestVector = vec;
      maxSize = vec.size();
    }
  }
  // TEST

  //  std::cout << "The largest vector is: ";
  //  for (const auto& num : largestVector) {
  //    std::cout << num << " ";
  //  }
  //  std::cout << std::endl;

  return largestVector;
}

string lcs(const string& x, const string& y) {
  string lcs = "";
  size_t head = 0;
  for (int i = 0; i < x.size(); ++i) {
    for (int j = head; j < y.size(); ++j) {
      if (x[i] == y[j]) {
        lcs += x[i];
        head = j;
        // TEST
        //        cout << x[i] << endl;
      }
    }
  }

  return lcs;
}
int main() {
  //  string x = "ABCDGH";
  //  string y = "AEHDFHR";
  //  string lcs = "";

  //  unsigned int head = 0;
  //  for (int i = 0; i < x.size(); ++i) {
  //    for (int j = head; j < y.size(); ++j) {
  //      if (x[i] == y[j]) {
  //        lcs += x[i];
  //        head = j;
  //        cout << x[i] << endl;
  //      }
  //    }
  //  }

  //  cout << lcs << endl;
  string x = "ABCDGH";
  string y = "AEHDFHR";
  string lcsOfXAndY = lcs(x, y);
  cout << lcsOfXAndY << endl;

  int arr[] = {10, 22, 9, 33, 21, 50, 41, 60};
  size_t arrSize = sizeof(arr) / sizeof(int);

  vector<int> lisOfArr = lis(arr, arrSize);
  for (auto elem : lisOfArr) {
    cout << elem << ", ";
  }
  cout << endl;
  return 0;
}
