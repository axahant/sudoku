#ifndef TOUCH_LISTENER_h
#define TOUCH_LISTENER_h

class TouchListener {

  private:
    int listenerCount;
    void (* listeners[6])(int x, int y);

  public:

    TouchListener() {
      listenerCount = 0;
    }

    void addListener(void (*listener)(int x, int y)) {
      listeners[listenerCount] = listener;
      listenerCount++;
    }

    void onTouch(int x, int y) {
      for (int n=0; n<=listenerCount; n++) {
        (*listeners[n])(x, y);
      }
    }

};

#endif
