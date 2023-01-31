## 6) Surface

<br>
<br>

5) Ray 클래스까지는 다른 해더파일에 크게 의존적이지 않다. 하지만 Surface클래스부터는 다양한 해더파일이 서로 영향을 미친다.

<br>
<br>

먼저 구조체 SurfaceRayIntersection2 이다.


```cpp
//! Struct that represents ray-surface intersection point.
struct SurfaceRayIntersection2 {
    bool isIntersecting = false;
    double distance = kMaxD;
    Vector2D point;
    Vector2D normal;
};
```

이 구조체는 Surface와 Ray가 만나는 점을 표현한 구조체이다. 


