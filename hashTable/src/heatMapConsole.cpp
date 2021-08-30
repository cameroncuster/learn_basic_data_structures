#include <fstream>
#include <iostream>
#include "function.h"
#include "hashTable.h"

using namespace std;

int main(int argc, char *argv[])
{
   char *filename;
   HashTable hash;
   std::ifstream inputStream;
   bool notDone = true;
   int emptyCount = 0;
   int highestCount = 0;

   if (argc < 2)
   {
      cout << "Usage: " << argv[0] << " text_file" << endl;
      return 0;
   }
   filename = argv[1];
   inputStream.open(filename, std::ios_base::in);

   while (notDone)
   {
      try
      {
         string nextWord = readNextWord(inputStream);
         hash[nextWord]++;
      }
      catch (const char *msg)
      {
         notDone = false;
      }
   }

   cout << "Words (Word - frequency of word in file)" << endl;
   for (string word : hash.getKeys())
      cout << "  " 
           << word << " - " << hash[word] << endl;

   cout << "Heatmap (index - chain length)" << endl;
   for(int i = 0; i < hash.tableSize(); i++)
   {
      if(hash.size(i)>0)
      {
         if(hash.size(i) > highestCount)
         {
            highestCount = hash.size(i);
         }
         cout << "  "
              << i << " - " << hash.size(i) << endl;
      } else {
         emptyCount++;
      }
   }

   cout << "Hash Table Stats" << endl;
   cout << "  Load Factor: " 
        << (float)hash.size()/hash.tableSize() << endl;
   cout << "  Empty Cells: " 
        << emptyCount << endl;
   cout << "  Highest Chain Length: " 
        << highestCount << endl;
   cout << "  Average Chain Length: " 
        << (float)hash.size()/(hash.tableSize()-emptyCount) << endl;
   cout << "      Size: " 
        << hash.size() << endl;
   cout << "  Capacity: " 
        << hash.tableSize() << endl;

   return 0;
}
