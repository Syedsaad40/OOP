#include <iostream>
#include <string>
using namespace std;

class MediaFile {
protected:
    string filepath;
    int size;
public:
    MediaFile(string s, int a) : filepath(s), size(a) {}

    virtual void play() {
        cout << "Media File: " << filepath << " being played.." << endl;
    }

    virtual void stop() {
        cout << "Media file: " << filepath << " being stopped" << endl;
    }

    virtual ~MediaFile() {
        cout << "Media File: " << filepath << " being destroyed" << endl;
    }
};

class VisualMedia : virtual public MediaFile {
protected:
    int resolution;
public:
    VisualMedia(string a, int b, int r) : MediaFile(a, b), resolution(r) {}

    void displayres() {
        cout << "Resolution: " << resolution << endl;
    }
};

class AudioMedia : virtual public MediaFile {
protected:
    int samplerate;
public:
    AudioMedia(string a, int b, int c) : MediaFile(a, b), samplerate(c) {}

    void displayrate() {
        cout << "Samplerate: " << samplerate << endl;
    }
};

class VideoFile : public VisualMedia, public AudioMedia {
public:
    VideoFile(string a, int b, int c, int d) : MediaFile(a, b), VisualMedia(a, b, c), AudioMedia(a, b, d) {}

    void play() override {
        cout << "Playing videofile: " << filepath << endl;
        displayrate();
        displayres();
    }

    void stop() override {
        cout << "Stopping videofile: " << filepath << endl;
    }
};

class ImageFile : public VisualMedia {
public:
    ImageFile(string a, int b, int c) : MediaFile(a, b), VisualMedia(a, b, c) {}

    void play() override {
        cout << "Playing image file: " << filepath << endl;
        displayres();
    }

    void stop() override {
        cout << "Stopping Image file: " << filepath << endl;
    }
};

class AudioFile : public AudioMedia {
public:
    AudioFile(string a, int b, int c) : MediaFile(a, b), AudioMedia(a, b, c) {}

    void play() override {
        cout << "Playing audio file: " << filepath << endl;
        displayrate();
    }

    void stop() override {
        cout << "Stopping audio file: " << filepath << endl;
    }
};

int main() {
    VideoFile video("video.mp4", 1024, 1080, 48000);
    ImageFile image("image.jpg", 512, 1920);
    AudioFile audio("audio.mp3", 256, 44100);

    MediaFile* mediaFiles[] = { &video, &image, &audio };

    for (MediaFile* file : mediaFiles) {
        file->play();
        file->stop();
        cout << "-------------------" << endl;
    }

    return 0;
}