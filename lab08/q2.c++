#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

const int WIDTH = 5;
const int HEIGHT = 7;

class Image {
private:
    int width, height;
    int* img_data;
public:
    Image(int w, int h, const int* data) : width(w), height(h) {
        img_data = new int[width * height];
        memcpy(img_data, data, width * height * sizeof(int));
    }

    Image(const Image& obj) : width(obj.width), height(obj.height) {
        img_data = new int[width * height];
        memcpy(img_data, obj.img_data, width * height * sizeof(int));
    }

    void display() {
        cout << "Image Specifications\n";
        cout << "Height: " << height << endl;
        cout << "Width: " << width << endl;
        cout << "Image Data: \n";
        for (int i = 0; i < width * height; ++i) {
            cout << img_data[i] << " ";
            if ((i + 1) % width == 0)
                cout << "\n";
        }
    }

    void updateData() {
        for (int i = 0; i < width * height; i++) {
            if (img_data[i] <= 0) {
                img_data[i] = rand() % 255 + 1;
            }
        }
    }

    ~Image() {
        delete[] img_data;
    }
};

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int data[WIDTH * HEIGHT] = {23, 76, 4, 29, 101, 908,12,12,232,32,54,66,767,787,98976,21,34455,676,3422121,5667,78,8,9,5,4,433,3,};
    Image img(WIDTH, HEIGHT, data);
    Image img2 = img;

    cout << "Original Image Specifications:\n";
    img.display();
    cout << "Copied Image Specifications:\n";
    img2.display();

    img.updateData();

    cout << "Original Image Specifications after Update:\n";
    img.display();
    cout << "Copied Image Specifications after Update:\n";
    img2.display();

    return 0;
}
