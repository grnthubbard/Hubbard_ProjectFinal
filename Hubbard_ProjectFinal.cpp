// Hubbard_FinalProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;


Image* blurring(Image data) {
	int width = data.getSize().x;
	int height = data.getSize().y;
	Image* result = new Image;
	result->create(width, height);
	for (int pixelY = 0; pixelY < height; pixelY++) {
		for (int pixelX = 0; pixelX < width; pixelX++) {
			int neighborCount = 0; //init neighbor count
			int redAcc = 0, greenAcc = 0, blueAcc = 0; // init RGB accumulators
			//find surrounding pixels, aware of borders
			int minX = max(pixelX - 1, 0);
			int maxX = min(pixelX + 1, width - 1);
			int minY = max(pixelY - 1, 0);
			int maxY = min(pixelY + 1, height - 1);
			for (int y = minY; y <= maxY; y++) {
				for (int x = minX; x <= maxX; x++) {
					Color neighborColor = data.getPixel(x, y);
					redAcc += neighborColor.r;
					greenAcc += neighborColor.g;
					blueAcc += neighborColor.b;
					neighborCount++;
				}
			}
			result->setPixel(pixelX, pixelY, Color(redAcc / neighborCount,
				greenAcc / neighborCount, blueAcc / neighborCount));
		}
	}
	return result;
}

Image* contrast(Image data) {
	int width = data.getSize().x;
	int height = data.getSize().y;
	Image* result = new Image;
	result->create(width, height);
	for (int pixelY = 0; pixelY < height; pixelY++) {
		for (int pixelX = 0; pixelX < width; pixelX++) {
			int neighborCount = 0; //init neighbor count
			int redAcc = 0, greenAcc = 0, blueAcc = 0; // init RGB accumulators
			//find surrounding pixels, aware of borders
			int minX = max(pixelX - 1, 0);
			int maxX = min(pixelX + 1, width - 1);
			int minY = max(pixelY - 1, 0);
			int maxY = min(pixelY + 1, height - 1);
			for (int y = minY; y <= maxY; y++) {
				for (int x = minX; x <= maxX; x++) {
					Color neighborColor = data.getPixel(x, y);
					redAcc += neighborColor.r;
					greenAcc += neighborColor.g;
					blueAcc += neighborColor.b;
					neighborCount++;
				}
			}
			result->setPixel(pixelX, pixelY, Color(redAcc / 2 / neighborCount,
				greenAcc / 2 / neighborCount, blueAcc / 2 / neighborCount));
		}
	}
	return result;
}



Image* invertColors(Image data) {
	int width = data.getSize().x;
	int height = data.getSize().y;
	Image* result = new Image;
	result->create(width, height);
	for (int pixelY = 0; pixelY < height; pixelY++) {
		for (int pixelX = 0; pixelX < width; pixelX++) {
			int neighborCount = 0; //init neighbor count
			int redAcc = 0, greenAcc = 0, blueAcc = 0; // init RGB accumulators
			//find surrounding pixels, aware of borders
			int minX = max(pixelX - 1, 0);
			int maxX = min(pixelX + 1, width - 1);
			int minY = max(pixelY - 1, 0);
			int maxY = min(pixelY + 1, height - 1);
			for (int y = minY; y <= maxY; y++) {
				for (int x = minX; x <= maxX; x++) {
					Color neighborColor = data.getPixel(x, y);
					redAcc -= neighborColor.r;
					greenAcc -= neighborColor.g;
					blueAcc -= neighborColor.b;
					neighborCount++;
				}
			}
			result->setPixel(pixelX, pixelY, Color(redAcc / neighborCount,
				greenAcc / neighborCount, blueAcc / neighborCount));
		}
	}
	return result;
}


int main()
{
	cout << "0. Quit" << endl << "1. Start Image Editor\n";
	int choice;
	int second_choice;
	cin >> choice;



	// First Menu
	switch (choice)
	{
	case 0:
		break;
	case 1:
		std::cout << "Let's Get Started!\n";
		// Second Menu
		cout << "What effects would you like to be applied to your image?\n";
		cout << "1. Invert Colors" << endl << "2. Blur" << endl << "3. Contrast"
			<< endl << "4. Green Screen" << endl << "5. None" << endl;
		cin >> second_choice;

		switch (second_choice)
		{
		case 1:
			//Invert Colors
		{
			Image sourceImg;
			sourceImg.loadFromFile("images/Purdue_Pete_modern.jpg");
			Image* result = invertColors(sourceImg);
			result->saveToFile("images/new_Purdue_Pete_modern.jpg");
			

			string image = "images/new_Purdue_Pete_modern.jpg";
			Texture imageTex;
			Image newImage;
			newImage = imageTex.copyToImage();
			if (!imageTex.loadFromFile(image)) {
				cout << "Couldn't Load Image" << endl;
				exit(1);
			}
			RenderWindow window(VideoMode(800, 532), "Here's your output. It's pretty creepy!");
			Sprite sprite1;
			imageTex.loadFromImage(newImage);
			sprite1.setTexture(imageTex);
			window.clear();
			window.draw(sprite1);
			window.display();
			while (true);
			delete "images/new_Purdue_Pete_modern.jpg";
		}
		case 2:
			//Blurring
		{
			Image sourceImg;
			sourceImg.loadFromFile("images/Purdue_Pete_modern.jpg");
			Image* result = blurring(sourceImg);
			result->saveToFile("images/blur_Purdue_Pete_modern.jpg");
			

			string image = "images/blur_Purdue_Pete_modern.jpg";
			Texture imageTex;
			Image newImage;
			newImage = imageTex.copyToImage();
			if (!imageTex.loadFromFile(image)) {
				cout << "Couldn't Load Image" << endl;
				exit(1);
			}
			RenderWindow window(VideoMode(800, 532), "Here's the output");
			Sprite sprite1;
			imageTex.loadFromImage(newImage);
			sprite1.setTexture(imageTex);
			window.clear();
			window.draw(sprite1);
			window.display();
			while (true);
		}
		case 3:
			//Gausian Blur
		{
			Image sourceImg;
			sourceImg.loadFromFile("images/Purdue_Pete_modern.jpg");
			Image* result = contrast(sourceImg);
			result->saveToFile("images/blur_Purdue_Pete_modern.jpg");


			string image = "images/blur_Purdue_Pete_modern.jpg";
			Texture imageTex;
			Image newImage;
			newImage = imageTex.copyToImage();
			if (!imageTex.loadFromFile(image)) {
				cout << "Couldn't Load Image" << endl;
				exit(1);
			}
			RenderWindow window(VideoMode(800, 532), "Here's the output");
			Sprite sprite1;
			imageTex.loadFromImage(newImage);
			sprite1.setTexture(imageTex);
			window.clear();
			window.draw(sprite1);
			window.display();
			while (true);
		}
		case 4:
			//Green Screen;
		{
			string background = "images/beach.png";
			string foreground = "images/pete-green.png";
			Texture backgroundTex;
			if (!backgroundTex.loadFromFile(background)) {
				cout << "Couldn't Load Image" << endl;
				exit(1);
			}
			Texture foregroundTex;
			if (!foregroundTex.loadFromFile(foreground)) {
				cout << "Couldn't Load Image" << endl;
				exit(1);
			}
			Image backgroundImage;
			backgroundImage = backgroundTex.copyToImage();
			Image foregroundImage;
			foregroundImage = foregroundTex.copyToImage();
			Vector2u sz = backgroundImage.getSize();
			Color greenScreen = foregroundImage.getPixel(0, 0);
			for (int y = 0; y < sz.y; y++) {
				for (int x = 0; x < sz.x; x++) {
					// These two loops will run the code inside for each pixel in the background image
						// You can access the current pixel at x,y like so:

					Color currentPixel = foregroundImage.getPixel(x, y);
					Color backGround = backgroundImage.getPixel(x, y);

					if (currentPixel.g == greenScreen.g)
					{
						foregroundImage.setPixel(x, y, backGround);
					}
					// Color objects store the individual channel values like example.r example.g and example.b
				}
			}
			RenderWindow window(VideoMode(1024, 768), "Here's the output");
			Sprite sprite1;
			Texture tex1;
			tex1.loadFromImage(foregroundImage);
			sprite1.setTexture(tex1);
			window.clear();
			window.draw(sprite1);
			window.display();
			while (true);
		}
		case 5:
			//Only shows picture
			string stock_image = "images/Purdue_Pete_modern.jpg";
			Texture stockTex;
			Image image1;
			image1 = stockTex.copyToImage();
			if (!stockTex.loadFromFile(stock_image)) {
				cout << "Couldn't Load Image" << endl;
				exit(1);
			}

			cout << "Here is your picture\n";
			RenderWindow window(VideoMode(800, 532), "Here's the output");
			Sprite sprite1;

			stockTex.loadFromImage(image1);
			sprite1.setTexture(stockTex);
			window.clear();
			window.draw(sprite1);
			window.display();
			while (true);

		}

	}


















}