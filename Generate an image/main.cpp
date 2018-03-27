#include <fstream>

using namespace std;

int height = 1500, width = 1500;

int main(){
   ofstream img("picture.ppm");
   img << "P3" << endl;
   img << width << " " << height << endl;
   img << "1500" << endl;

   for (int y = 0 ; y < height; y++){
        for (int x = 0 ; x < width; x++){

            int r = x%1500;
            int g = y%1500;
            int b = x*y%1500;

            img << r << " " << g << " " << b << endl;
   }
   }

  // system("open picture.ppm");
   img.open("picture.ppm");
   return 0;
}
