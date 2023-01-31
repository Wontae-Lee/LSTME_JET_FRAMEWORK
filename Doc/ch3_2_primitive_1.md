# 2. Primitive

Jet Framework (jet)는 가장 먼저 Data structure를 정의하는 지점부터 시작한다. Data structure는 numerical simulation <br>
에서 "세계를 어떻게 정의할까"를 의미한다. 즉, 공학자는 시뮬레이션 안에서 만물을 조작하는 신이 된다. 

jet에서는 가장 기본적인 data structure를 Point 클래스로 정의하였다. 

***

## 1) Point

```cpp
template <typename T, size_t N>
class Point final {
 public:
    static_assert(N > 0, "Size of static-sized point should be greater than zero.");
    static_assert(std::is_arithmetic<T>::value, "Point only can be instantiated with arithmetic types");

    //! Constructs a point with zeros.
    Point();

    //! Constructs point instance with parameters.
    template <typename... Params>
    explicit Point(Params... params);

    //! Constructs point instance with initializer list.
    template <typename U>
    Point(const std::initializer_list<U>& lst);

    //! Copy constructor.
    Point(const Point& other);

    //! Set point instance with initializer list.
    template <typename U>
    void set(const std::initializer_list<U>& lst);

    //! Set point instance with other point.
    void set(const Point& other);

    //! Set point instance with initializer list.
    template <typename U>
    Point& operator=(const std::initializer_list<U>& lst);

    //! Set point instance with other point.
    Point& operator=(const Point& other);

    //! Returns the const reference to the \p i -th element.
    const T& operator[](size_t i) const;

    //! Returns the reference to the \p i -th element.
    T& operator[](size_t);

 private:
    std::array<T, N> _elements;

    template <typename... Params>
    void setAt(size_t i, T v, Params... params);

    void setAt(size_t i, T v);
};


```

Point 클래스는 어떤 차원의 점을 나타낸다. Point 클래스를 생성할 때에는 기본적인 데이터 타입 T (int, double, 등) 과 그 점이 존재하는 차원의 차수 N를 입력해야만 클래스가 생성된다. 맴버함수로는 기본적인 생성자들 (initializer_list, copy) 과 setter 와 getter를 가지고 있고 , 맴버변수로 각차원의 점에 대한 정보를 가지고 있다. 점은 STL에 std::array 에 그 정보가 담긴다. 
예를들어, std::array _elements = {x, y, z} 

```cpp
 //! Computes this + (v, v).
    Point add(T v) const;

    //! Computes this + (v.x, v.y).
    Point add(const Point& v) const;

    //! Computes this - (v, v).
    Point sub(T v) const;

    //! Computes this - (v.x, v.y).
    Point sub(const Point& v) const;

    //! Computes this * (v, v).
    Point mul(T v) const;

    //! Computes this * (v.x, v.y).
    Point mul(const Point& v) const;

    //! Computes this / (v, v).
    Point div(T v) const;

    //! Computes this / (v.x, v.y).
    Point div(const Point& v) const;

    // MARK: Binary operations: new instance = v (+) this

    //! Computes (v, v) - this.
    Point rsub(T v) const;

    //! Computes (v.x, v.y) - this.
    Point rsub(const Point& v) const;

    //! Computes (v, v) / this.
    Point rdiv(T v) const;

    //! Computes (v.x, v.y) / this.
    Point rdiv(const Point& v) const;

    // MARK: Augmented operations: this (+)= v

    //! Computes this += (v, v).
    void iadd(T v);

    //! Computes this += (v.x, v.y).
    void iadd(const Point& v);

    //! Computes this -= (v, v).
    void isub(T v);

    //! Computes this -= (v.x, v.y).
    void isub(const Point& v);

    //! Computes this *= (v, v).
    void imul(T v);

    //! Computes this *= (v.x, v.y).
    void imul(const Point& v);

    //! Computes this /= (v, v).
    void idiv(T v);

    //! Computes this /= (v.x, v.y).
    void idiv(const Point& v);

    // MARK: Basic getters

    //! Returns const reference to the \p i -th element of the point.
    const T& at(size_t i) const;

    //! Returns reference to the \p i -th element of the point.
    T& at(size_t i);

    //! Returns the sum of all the components (i.e. x + y).
    T sum() const;

    //! Returns the minimum value among x and y.
    T min() const;

    //! Returns the maximum value among x and y.
    T max() const;

    //! Returns the absolute minimum value among x and y.
    T absmin() const;

    //! Returns the absolute maximum value among x and y.
    T absmax() const;

    //! Returns the index of the dominant axis.
    size_t dominantAxis() const;

    //! Returns the index of the subminant axis.
    size_t subminantAxis() const;

    //! Returns a point with different value type.
    template <typename U>
    Point<U, 2> castTo() const;

    //! Returns true if \p other is the same as this point.
    bool isEqual(const Point& other) const;

    // MARK: Operators

    //! Returns reference to the \p i -th element of the point.
    T& operator[](size_t i);

    //! Returns const reference to the \p i -th element of the point.
    const T& operator[](size_t i) const;

    //! Set x and y components with given initializer list.
    Point& operator=(const std::initializer_list<T>& lst);

    //! Set x and y with other point \p pt.
    Point& operator=(const Point& v);

    //! Computes this += (v, v)
    Point& operator+=(T v);

    //! Computes this += (v.x, v.y)
    Point& operator+=(const Point& v);

    //! Computes this -= (v, v)
    Point& operator-=(T v);

    //! Computes this -= (v.x, v.y)
    Point& operator-=(const Point& v);

    //! Computes this *= (v, v)
    Point& operator*=(T v);

    //! Computes this *= (v.x, v.y)
    Point& operator*=(const Point& v);

    //! Computes this /= (v, v)
    Point& operator/=(T v);

    //! Computes this /= (v.x, v.y)
    Point& operator/=(const Point& v);

    //! Returns true if \p other is the same as this point.
    bool operator==(const Point& v) const;

    //! Returns true if \p other is the not same as this point.
    bool operator!=(const Point& v) const;

```

2차원과 3차원의 Point <T, 2>, Point <T, 3>에서는 각 포인트의 좌표 (x, y) 또는 (x, y, z) 를 연산하는 맴버 함수가 추가되어 있다. (imax, imin, operator +=, 등)


***

## 2) Size

Size 클래스 역시 1차원, 2차원, 3차원으로 나눠지게 된다. 각 차원마다 size_t x, size_t y, size_t z 로 각 차원에서의 크기를 나타내는데, 중요한 점이 x, y, z가 절대적인 길이를 표현하는 것이 아니다. x, y, z는 각 차원에서 데이터를 각각 몇개씩 가지고 있는지, 즉 1차원 2차원 3차원 행렬에서의 크기를 가르키는 것이다.




```cpp

namespace jet {

//!
//! \brief 2-D size class.
//!
//! This class defines simple 2-D size data.
//!
class Size2 {
 public:
    //! X (or the first) component of the size.
    size_t x;

    //! Y (or the second) component of the size.
    size_t y;

    // MARK: Constructors

    //! Constructs default size (0, 0).
    constexpr Size2() : x(0), y(0) {}

    //! Constructs size with given parameters \p x_ and \p y_.
    constexpr Size2(size_t x_, size_t y_) : x(x_), y(y_) {}

    //! Constructs size with initializer list.
    template <typename U>
    Size2(const std::initializer_list<U>& lst);

    //! Copy constructor.
    constexpr Size2(const Size2& v) : x(v.x), y(v.y) {}

    // MARK: Basic setters

    //! Set both x and y components to \p s.
    void set(size_t s);

    //! Set x and y components with given parameters.
    void set(size_t x, size_t y);

    //! Set x and y components with given initializer list.
    template <typename U>
    void set(const std::initializer_list<U>& lst);

    //! Set x and y with other size \p pt.
    void set(const Size2& pt);

    //! Set both x and y to zero.
    void setZero();

    // MARK: Binary operations: new instance = this (+) v

    //! Computes this + (v, v).
    Size2 add(size_t v) const;

    //! Computes this + (v.x, v.y).
    Size2 add(const Size2& v) const;

    //! Computes this - (v, v).
    Size2 sub(size_t v) const;

    //! Computes this - (v.x, v.y).
    Size2 sub(const Size2& v) const;

    //! Computes this * (v, v).
    Size2 mul(size_t v) const;

    //! Computes this * (v.x, v.y).
    Size2 mul(const Size2& v) const;

    //! Computes this / (v, v).
    Size2 div(size_t v) const;

    //! Computes this / (v.x, v.y).
    Size2 div(const Size2& v) const;

    // MARK: Binary operations: new instance = v (+) this

    //! Computes (v, v) - this.
    Size2 rsub(size_t v) const;

    //! Computes (v.x, v.y) - this.
    Size2 rsub(const Size2& v) const;

    //! Computes (v, v) / this.
    Size2 rdiv(size_t v) const;

    //! Computes (v.x, v.y) / this.
    Size2 rdiv(const Size2& v) const;

    // MARK: Augmented operations: this (+)= v

    //! Computes this += (v, v).
    void iadd(size_t v);

    //! Computes this += (v.x, v.y).
    void iadd(const Size2& v);

    //! Computes this -= (v, v).
    void isub(size_t v);

    //! Computes this -= (v.x, v.y).
    void isub(const Size2& v);

    //! Computes this *= (v, v).
    void imul(size_t v);

    //! Computes this *= (v.x, v.y).
    void imul(const Size2& v);

    //! Computes this /= (v, v).
    void idiv(size_t v);

    //! Computes this /= (v.x, v.y).
    void idiv(const Size2& v);

    // MARK: Basic getters

    //! Returns const reference to the \p i -th element of the size.
    const size_t& at(size_t i) const;

    //! Returns reference to the \p i -th element of the size.
    size_t& at(size_t i);

    //! Returns the sum of all the components (i.e. x + y).
    size_t sum() const;

    //! Returns the minimum value among x and y.
    size_t min() const;

    //! Returns the maximum value among x and y.
    size_t max() const;

    //! Returns the absolute minimum value among x and y.
    size_t absmin() const;

    //! Returns the absolute maximum value among x and y.
    size_t absmax() const;

    //! Returns the index of the dominant axis.
    size_t dominantAxis() const;

    //! Returns the index of the subminant axis.
    size_t subminantAxis() const;

    //! Returns true if \p other is the same as this size.
    bool isEqual(const Size2& other) const;

    // MARK: Operators

    //! Returns reference to the \p i -th element of the size.
    size_t& operator[](size_t i);

    //! Returns const reference to the \p i -th element of the size.
    const size_t& operator[](size_t i) const;

    //! Set x and y components with given initializer list.
    template <typename U>
    Size2& operator=(const std::initializer_list<U>& lst);

    //! Set x and y with other size \p pt.
    Size2& operator=(const Size2& v);

    //! Computes this += (v, v)
    Size2& operator+=(size_t v);

    //! Computes this += (v.x, v.y)
    Size2& operator+=(const Size2& v);

    //! Computes this -= (v, v)
    Size2& operator-=(size_t v);

    //! Computes this -= (v.x, v.y)
    Size2& operator-=(const Size2& v);

    //! Computes this *= (v, v)
    Size2& operator*=(size_t v);

    //! Computes this *= (v.x, v.y)
    Size2& operator*=(const Size2& v);

    //! Computes this /= (v, v)
    Size2& operator/=(size_t v);

    //! Computes this /= (v.x, v.y)
    Size2& operator/=(const Size2& v);

    //! Returns true if \p other is the same as this size.
    bool operator==(const Size2& v) const;

    //! Returns true if \p other is the not same as this size.
    bool operator!=(const Size2& v) const;
};

//! Positive sign operator.
Size2 operator+(const Size2& a);

//! Negative sign operator.
Size2 operator-(const Size2& a);

//! Computes (a, a) + (b.x, b.y).
Size2 operator+(size_t a, const Size2& b);

//! Computes (a.x, a.y) + (b.x, b.y).
Size2 operator+(const Size2& a, const Size2& b);

//! Computes (a.x, a.y) - (b, b).
Size2 operator-(const Size2& a, size_t b);

//! Computes (a, a) - (b.x, b.y).
Size2 operator-(size_t a, const Size2& b);

//! Computes (a.x, a.y) - (b.x, b.y).
Size2 operator-(const Size2& a, const Size2& b);

//! Computes (a.x, a.y) * (b, b).
Size2 operator*(const Size2& a, size_t b);

//! Computes (a, a) * (b.x, b.y).
Size2 operator*(size_t a, const Size2& b);

//! Computes (a.x, a.y) * (b.x, b.y).
Size2 operator*(const Size2& a, const Size2& b);

//! Computes (a.x, a.y) / (b, b).
Size2 operator/(const Size2& a, size_t b);

//! Computes (a, a) / (b.x, b.y).
Size2 operator/(size_t a, const Size2& b);

//! Computes (a.x, a.y) / (b.x, b.y).
Size2 operator/(const Size2& a, const Size2& b);

//! Returns element-wise min size: (min(a.x, b.x), min(a.y, b.y)).
Size2 min(const Size2& a, const Size2& b);

//! Returns element-wise max size: (max(a.x, b.x), max(a.y, b.y)).
Size2 max(const Size2& a, const Size2& b);

//! Returns element-wise clamped size.
Size2 clamp(const Size2& v, const Size2& low, const Size2& high);

//! Returns element-wise ceiled size.
Size2 ceil(const Size2& a);

//! Returns element-wise floored size.
Size2 floor(const Size2& a);

}  // namespace jet

```

Size 클래스도 맴버함수로 연산자, 생성자, 소멸자 외에 min, max, clamp, 등 각 맴버변수 x, y, z에 관련된 유용한 함수를 포함하고 있다. 

<br>
<br>

***

## 3) Array

<br>
<br>

사용법은 std::array와 흡사하지만 내부적으로는 std::vector로 구현되어 있다.(std::array는 배열의 길이를 바꾸지 못해서 std::vector로 구현한 듯 보인다.) jet에서 가장 대표적인 data container이고 3가지 클래스로 구현되어 있다. Data container로서의 Array<T,N>와 각 Array<T,N>를 조작하는 ArrayAccessor<T, N>, 샘플링을 하는 ArraySampler<T, N> 이 그것들이다.

<br>
<br>

jet에서는 각 차원별로 따로 std::vector로 구현하지 않았다. 그 이유는 간단하게 설명하자면 각 차원 메모리 주소값에 접근을 용이하게 하기 위해서 이다. 3차원의 배열을 [1,1,1,1,1,2,2,2,2,3,3,3,3] 처럼 (1,2,3 은 각 차원의 배열주소) 설계하는 것이 각각 [1,1,1,1], [2,2,2,2], [3,3,3,3] 처럼 배열하는 것보다 더 빠르게 다른 차원의 주소에 접근한다. 더욱 자세한 이야기는 [Optimized c++]()를 참조하기 바란다.

<br>
<br>

### (1) Array

<br>
<br>

Array<T,N> 는 다음과 같다.

<br>
<br>

```cpp
namespace jet {

//!
//! \brief 2-D array class.
//!
//! This class represents 2-D array data structure. Internally, the 2-D data is
//! mapped to a linear array such that (i, j) element is actually stroed at
//! (i + (width * j))th element of the linear array. This mapping means
//! iterating i first and j next will give better performance such as:
//!
//! \code{.cpp}
//! Array<int, 2> array;
//! for (size_t j = 0; j < array.height(); ++j) {
//!     for (size_t i = 0; i < array.width(); ++i) {
//!         // Read or write array(i, j)
//!     }
//! }
//! \endcode
//!
//! \tparam T - Type to store in the array.
//!
template <typename T>
class Array<T, 2> final {
 public:
    typedef std::vector<T> ContainerType;
    typedef typename ContainerType::iterator Iterator;
    typedef typename ContainerType::const_iterator ConstIterator;

    //! Constructs zero-sized 2-D array.
    Array();

    //! Constructs 2-D array with given \p size and fill it with \p initVal.
    //! \param size Initial size of the array.
    //! \param initVal Initial value of each array element.
    explicit Array(const Size2& size, const T& initVal = T());

    //! Constructs 2-D array with size \p width x \p height and fill it with
    //! \p initVal.
    //! \param width Initial width of the array.
    //! \param height Initial height of the array.
    //! \param initVal Initial value of each array element.
    Array(size_t width, size_t height, const T& initVal = T());

    //!
    //! \brief Constructs 2-D array with given initializer list \p lst.
    //!
    //! This constructor will build 2-D array with given initializer list \p lst
    //! such as
    //!
    //! \code{.cpp}
    //! Array<int, 2> arr = {
    //!     {1, 2, 4},
    //!     {9, 3, 5}
    //! };
    //! \endcode
    //!
    //! Note the initializer also has 2-D structure. The code above will
    //! construct 3 x 2 array.
    //!
    //! \param lst Initializer list that should be copy to the new array.
    //!
    Array(const std::initializer_list<std::initializer_list<T>>& lst);

    //! Copy constructor.
    Array(const Array<T,2>& other);

    //! Move constructor.
    Array(Array<T,2>&& other);

    //! Sets entire array with given \p value.
    void set(const T& value);

    //! Copies given array \p other to this array.
    void set(const Array<T,2>& other);

    //!
    //! Copies given initializer list \p lst to this array.
    //!
    //! This function copies given initializer list \p lst to the array such as
    //!
    //! \code{.cpp}
    //! Array<int, 2> arr;
    //! arr = {
    //!     {1, 2, 4},
    //!     {9, 3, 5}
    //! };
    //! \endcode
    //!
    //! Note the initializer also has 2-D structure. The code above will
    //! build 3 x 2 array.
    //!
    //! \param lst Initializer list that should be copy to the new array.
    //!
    void set(const std::initializer_list<std::initializer_list<T>>& lst);

    //! Clears the array and resizes to zero.
    void clear();

    //! Resizes the array with \p size and fill the new element with \p initVal.
    void resize(const Size2& size, const T& initVal = T());

    //! Resizes the array with size \p width x \p height and fill the new
    //! element with \p initVal.
    void resize(size_t width, size_t height, const T& initVal = T());

    //!
    //! \brief Returns the reference to the i-th element.
    //!
    //! This function returns the reference to the i-th element of the array
    //! where i is the index of linearly mapped elements such that
    //! i = x + (width * y) (x and y are the 2-D coordinates of the element).
    //!
    T& at(size_t i);

    //!
    //! \brief Returns the const reference to the i-th element.
    //!
    //! This function returns the const reference to the i-th element of the
    //! array where i is the index of linearly mapped elements such that
    //! i = x + (width * y) (x and y are the 2-D coordinates of the element).
    //!
    const T& at(size_t i) const;

    //! Returns the reference to the element at (pt.x, pt.y).
    T& at(const Point2UI& pt);

    //! Returns the const reference to the element at (pt.x, pt.y).
    const T& at(const Point2UI& pt) const;

    //! Returns the reference to the element at (i, j).
    T& at(size_t i, size_t j);

    //! Returns the const reference to the element at (i, j).
    const T& at(size_t i, size_t j) const;

    //! Returns the size of the array.
    Size2 size() const;

    //! Returns the width of the array.
    size_t width() const;

    //! Returns the height of the array.
    size_t height() const;

    //! Returns the raw pointer to the array data.
    T* data();

    //! Returns the const raw pointer to the array data.
    const T* const data() const;

    //! Returns the begin iterator of the array.
    Iterator begin();

    //! Returns the begin const iterator of the array.
    ConstIterator begin() const;

    //! Returns the end iterator of the array.
    Iterator end();

    //! Returns the end const iterator of the array.
    ConstIterator end() const;

    //! Returns the array accessor.
    ArrayAccessor2<T> accessor();

    //! Returns the const array accessor.
    ConstArrayAccessor2<T> constAccessor() const;

    //! Swaps the content of the array with \p other array.
    void swap(Array& other);

    //!
    //! \brief Iterates the array and invoke given \p func for each index.
    //!
    //! This function iterates the array elements and invoke the callback
    //! function \p func. The callback function takes array's element as its
    //! input. The order of execution will be the same as the nested for-loop
    //! below:
    //!
    //! \code{.cpp}
    //! Array<int, 2> array;
    //! for (size_t j = 0; j < array.height(); ++j) {
    //!     for (size_t i = 0; i < array.width(); ++i) {
    //!         func(array(i, j));
    //!     }
    //! }
    //! \endcode
    //!
    //! Below is the sample usage:
    //!
    //! \code{.cpp}
    //! Array<int, 2> array(100, 200, 4);
    //! array.forEach([](int elem) {
    //!     printf("%d\n", elem);
    //! });
    //! \endcode
    //!
    template <typename Callback>
    void forEach(Callback func) const;

    //!
    //! \brief Iterates the array and invoke given \p func for each index.
    //!
    //! This function iterates the array elements and invoke the callback
    //! function \p func. The callback function takes two parameters which are
    //! the (i, j) indices of the array. The order of execution will be the same
    //! as the nested for-loop below:
    //!
    //! \code{.cpp}
    //! Array<int, 2> array;
    //! for (size_t j = 0; j < array.height(); ++j) {
    //!     for (size_t i = 0; i < array.width(); ++i) {
    //!         func(i, j);
    //!     }
    //! }
    //! \endcode
    //!
    //! Below is the sample usage:
    //!
    //! \code{.cpp}
    //! Array<int, 2> array(10, 20, 4);
    //! array.forEachIndex([&](size_t i, size_t j) {
    //!     array(i, j) = 4.f * i + 7.f * j + 1.5f;
    //! });
    //! \endcode
    //!
    template <typename Callback>
    void forEachIndex(Callback func) const;

    //!
    //! \brief Iterates the array and invoke given \p func for each index in
    //!     parallel.
    //!
    //! This function iterates the array elements and invoke the callback
    //! function \p func. The callback function takes array's element as its
    //! input. The order of execution will be non-deterministic since it runs in
    //! parallel. Below is the sample usage:
    //!
    //! \code{.cpp}
    //! Array<int, 2> array(100, 200, 4);
    //! array.parallelForEach([](int& elem) {
    //!     elem *= 2;
    //! });
    //! \endcode
    //!
    //! The parameter type of the callback function doesn't have to be T&, but
    //! const T& or T can be used as well.
    //!
    template <typename Callback>
    void parallelForEach(Callback func);

    //!
    //! \brief Iterates the array and invoke given \p func for each index in
    //!     parallel using multi-threading.
    //!
    //! This function iterates the array elements and invoke the callback
    //! function \p func in parallel using multi-threading. The callback
    //! function takes two parameters which are the (i, j) indices of the array.
    //! The order of execution will be non-deterministic since it runs in
    //! parallel. Below is the sample usage:
    //!
    //! \code{.cpp}
    //! Array<int, 2> array(100, 200, 4);
    //! array.parallelForEachIndex([&](size_t i, size_t j) {
    //!     array(i, j) *= 2;
    //! });
    //! \endcode
    //!
    template <typename Callback>
    void parallelForEachIndex(Callback func) const;

    //!
    //! \brief Returns the reference to the i-th element.
    //!
    //! This function returns the reference to the i-th element of the array
    //! where i is the index of linearly mapped elements such that
    //! i = x + (width * y) (x and y are the 2-D coordinates of the element).
    //!
    //! \see Array<T, 2>::at
    //!
    T& operator[](size_t i);

    //!
    //! \brief Returns the const reference to the i-th element.
    //!
    //! This function returns the const reference to the i-th element of the
    //! array where i is the index of linearly mapped elements such that
    //! i = x + (width * y) (x and y are the 2-D coordinates of the element).
    //!
    //! \see Array<T, 2>::at
    //!
    const T& operator[](size_t i) const;

    //! Returns the reference to the element at (pt.x, pt.y).
    T& operator()(const Point2UI& pt);

    //! Returns the const reference to the element at (pt.x, pt.y).
    const T& operator()(const Point2UI& pt) const;

    //! Returns the reference to the element at (i, j).
    T& operator()(size_t i, size_t j);

    //! Returns the const reference to the element at (i, j).
    const T& operator()(size_t i, size_t j) const;

    //! Sets entire array with given \p value.
    Array& operator=(const T& other);

    //! Copies given array \p other to this array.
    Array& operator=(const Array& other);

    //! Move assignment.
    Array& operator=(Array&& other);

    //!
    //! Copies given initializer list \p lst to this array.
    //!
    //! This function copies given initializer list \p lst to the array such as
    //!
    //! \code{.cpp}
    //! Array<int, 2> arr;
    //! arr = {
    //!     {1, 2, 4},
    //!     {9, 3, 5}
    //! };
    //! \endcode
    //!
    //! Note the initializer also has 2-D structure. The code above will
    //! build 3 x 2 array.
    //!
    //! \param lst Initializer list that should be copy to the new array.
    //!
    Array& operator=(const std::initializer_list<std::initializer_list<T>>& lst);

    //! Casts to array accessor.
    operator ArrayAccessor2<T>();

    //! Casts to const array accessor.
    operator ConstArrayAccessor2<T>() const;

 private:
    Size2 _size;
    std::vector<T> _data;
};
} // namespace jet
```

<br>
<br>

### (2) ArrayAccessor



ArrayAccessor<T, N> 는 각 차원의 Array<T,N>에 접근하여, 데이터를 읽고 쓰는 클래스이다. 앞서 언급했던 Array<T,N>이 차원별로 따로 Array를 가지고 있지 않아서 통상적인 std::vector형식의 접근이 불가능하여 만들어진 클래스이다.

```cpp
namespace jet {

//!
//! \brief 2-D array accessor class.
//!
//! This class represents 2-D array accessor. Array accessor provides array-like
//! data read/write functions, but does not handle memory management. Thus, it
//! is more like a random access iterator, but with multi-dimension support.
//! Similar to Array<T, 2>, this class interprets a linear array as a 2-D array
//! using i-major indexing.
//!
//! \see Array<T, 2>
//!
//! \tparam T - Array value type.
//!
template <typename T>
class ArrayAccessor<T, 2> final {
 public:
    //! Constructs empty 2-D array accessor.
    ArrayAccessor();

    //! Constructs an array accessor that wraps given array.
    //! \param size Size of the 2-D array.
    //! \param data Raw array pointer.
    ArrayAccessor(const Size2& size, T* const data);

    //! Constructs an array accessor that wraps given array.
    //! \param width Width of the 2-D array.
    //! \param height Height of the 2-D array.
    //! \param data Raw array pointer.
    ArrayAccessor(size_t width, size_t height, T* const data);

    //! Copy constructor.
    ArrayAccessor(const ArrayAccessor<T,2>& other);

    //! Replaces the content with given \p other array accessor.
    void set(const ArrayAccessor<T,2>& other);

    //! Resets the array.
    void reset(const Size2& size, T* const data);

    //! Resets the array.
    void reset(size_t width, size_t height, T* const data);

    //! Returns the reference to the i-th element.
    T& at(size_t i);

    //! Returns the const reference to the i-th element.
    const T& at(size_t i) const;

    //! Returns the reference to the element at (pt.x, pt.y).
    T& at(const Point2UI& pt);

    //! Returns the const reference to the element at (pt.x, pt.y).
    const T& at(const Point2UI& pt) const;

    //! Returns the reference to the element at (i, j).
    T& at(size_t i, size_t j);

    //! Returns the const reference to the element at (i, j).
    const T& at(size_t i, size_t j) const;

    //! Returns the begin iterator of the array.
    T* const begin() const;

    //! Returns the end iterator of the array.
    T* const end() const;

    //! Returns the begin iterator of the array.
    T* begin();

    //! Returns the end iterator of the array.
    T* end();

    //! Returns the size of the array.
    Size2 size() const;

    //! Returns the width of the array.
    size_t width() const;

    //! Returns the height of the array.
    size_t height() const;

    //! Returns the raw pointer to the array data.
    T* const data() const;

    //! Swaps the content of with \p other array accessor.
    void swap(ArrayAccessor<T,2>& other);

    //!
    //! \brief Iterates the array and invoke given \p func for each index.
    //!
    //! This function iterates the array elements and invoke the callback
    //! function \p func. The callback function takes array's element as its
    //! input. The order of execution will be the same as the nested for-loop
    //! below:
    //!
    //! \code{.cpp}
    //! int data = {1, 2, 3, 4, 5, 6};
    //! ArrayAccessor<int, 2> acc(2, 3, data);
    //! for (size_t j = 0; j < acc.height(); ++j) {
    //!     for (size_t i = 0; i < acc.width(); ++i) {
    //!         func(acc(i, j));
    //!     }
    //! }
    //! \endcode
    //!
    //! Below is the sample usage:
    //!
    //! \code{.cpp}
    //! int data = {1, 2, 3, 4, 5, 6};
    //! ArrayAccessor<int, 2> acc(2, 3, data);
    //! acc.forEach([](int elem) {
    //!     printf("%d\n", elem);
    //! });
    //! \endcode
    //!
    template <typename Callback>
    void forEach(Callback func) const;

    //!
    //! \brief Iterates the array and invoke given \p func for each index.
    //!
    //! This function iterates the array elements and invoke the callback
    //! function \p func. The callback function takes two parameters which are
    //! the (i, j) indices of the array. The order of execution will be the same
    //! as the nested for-loop below:
    //!
    //! \code{.cpp}
    //! int data = {1, 2, 3, 4, 5, 6};
    //! ArrayAccessor<int, 2> acc(2, 3, data);
    //! for (size_t j = 0; j < acc.height(); ++j) {
    //!     for (size_t i = 0; i < acc.width(); ++i) {
    //!         func(i, j);
    //!     }
    //! }
    //! \endcode
    //!
    //! Below is the sample usage:
    //!
    //! \code{.cpp}
    //! int data = {1, 2, 3, 4, 5, 6};
    //! ArrayAccessor<int, 2> acc(2, 3, data);
    //! acc.forEachIndex([&](size_t i, size_t j) {
    //!     acc(i, j) = 4.f * i + 7.f * j + 1.5f;
    //! });
    //! \endcode
    //!
    template <typename Callback>
    void forEachIndex(Callback func) const;

    //!
    //! \brief Iterates the array and invoke given \p func for each index in
    //!     parallel.
    //!
    //! This function iterates the array elements and invoke the callback
    //! function \p func. The callback function takes array's element as its
    //! input. The order of execution will be non-deterministic since it runs in
    //! parallel. Below is the sample usage:
    //!
    //! \code{.cpp}
    //! int data = {1, 2, 3, 4, 5, 6};
    //! ArrayAccessor<int, 2> acc(2, 3, data);
    //! acc.parallelForEach([](int& elem) {
    //!     elem *= 2;
    //! });
    //! \endcode
    //!
    //! The parameter type of the callback function doesn't have to be T&, but
    //! const T& or T can be used as well.
    //!
    template <typename Callback>
    void parallelForEach(Callback func);

    //!
    //! \brief Iterates the array and invoke given \p func for each index in
    //!     parallel using multi-threading.
    //!
    //! This function iterates the array elements and invoke the callback
    //! function \p func in parallel using multi-threading. The callback
    //! function takes two parameters which are the (i, j) indices of the array.
    //! The order of execution will be non-deterministic since it runs in
    //! parallel. Below is the sample usage:
    //!
    //! \code{.cpp}
    //! int data = {1, 2, 3, 4, 5, 6};
    //! ArrayAccessor<int, 2> acc(2, 3, data);
    //! acc.parallelForEachIndex([&](size_t i, size_t j) {
    //!     acc(i, j) *= 2;
    //! });
    //! \endcode
    //!
    template <typename Callback>
    void parallelForEachIndex(Callback func) const;

    //! Returns the linear index of the given 2-D coordinate (pt.x, pt.y).
    size_t index(const Point2UI& pt) const;

    //! Returns the linear index of the given 2-D coordinate (i, j).
    size_t index(size_t i, size_t j) const;

    //! Returns the reference to the i-th element.
    T& operator[](size_t i);

    //! Returns the const reference to the i-th element.
    const T& operator[](size_t i) const;

    //! Returns the reference to the element at (pt.x, pt.y).
    T& operator()(const Point2UI& pt);

    //! Returns the const reference to the element at (pt.x, pt.y).
    const T& operator()(const Point2UI& pt) const;

    //! Returns the reference to the element at (i, j).
    T& operator()(size_t i, size_t j);

    //! Returns the const reference to the element at (i, j).
    const T& operator()(size_t i, size_t j) const;

    //! Copies given array accessor \p other.
    ArrayAccessor& operator=(const ArrayAccessor<T,2>& other);

    //! Casts type to ConstArrayAccessor.
    operator ConstArrayAccessor<T, 2>() const;

 private:
    Size2 _size;
    T* _data;
};

//! Type alias for 2-D array accessor.
template <typename T>
using ArrayAccessor2 = ArrayAccessor<T, 2>;

//!
//! \brief 2-D read-only array accessor class.
//!
//! This class represents 2-D read-only array accessor. Array accessor provides
//! array-like data read/write functions, but does not handle memory management.
//! Thus, it is more like a random access iterator, but with multi-dimension
//! support. Similar to Array2<T, 2>, this class interprets a linear array as a
//! 2-D array using i-major indexing.
//!
//! \see Array2<T, 2>
//!
template <typename T>
class ConstArrayAccessor<T, 2> {
 public:
    //! Constructs empty 2-D read-only array accessor.
    ConstArrayAccessor();

    //! Constructs a read-only array accessor that wraps given array.
    //! \param size Size of the 2-D array.
    //! \param data Raw array pointer.
    ConstArrayAccessor(const Size2& size, const T* const data);

    //! Constructs an array accessor that wraps given array.
    //! \param width Width of the 2-D array.
    //! \param height Height of the 2-D array.
    //! \param data Raw array pointer.
    ConstArrayAccessor(size_t width, size_t height, const T* const data);

    //! Constructs a read-only array accessor from read/write accessor.
    explicit ConstArrayAccessor(const ArrayAccessor<T, 2>& other);

    //! Copy constructor.
    ConstArrayAccessor(const ConstArrayAccessor& other);

    //! Returns the reference to the i-th element.
    const T& at(size_t i) const;

    //! Returns the const reference to the element at (pt.x, pt.y).
    const T& at(const Point2UI& pt) const;

    //! Returns the const reference to the element at (i, j).
    const T& at(size_t i, size_t j) const;

    //! Returns the begin iterator of the array.
    const T* const begin() const;

    //! Returns the end iterator of the array.
    const T* const end() const;

    //! Returns the size of the array.
    Size2 size() const;

    //! Returns the width of the array.
    size_t width() const;

    //! Returns the height of the array.
    size_t height() const;

    //! Returns the raw pointer to the array data.
    const T* const data() const;

    //!
    //! \brief Iterates the array and invoke given \p func for each index.
    //!
    //! This function iterates the array elements and invoke the callback
    //! function \p func. The callback function takes array's element as its
    //! input. The order of execution will be the same as the nested for-loop
    //! below:
    //!
    //! \code{.cpp}
    //! int data = {1, 2, 3, 4, 5, 6};
    //! ConstArrayAccessor<int, 2> acc(2, 3, data);
    //! for (size_t j = 0; j < acc.height(); ++j) {
    //!     for (size_t i = 0; i < acc.width(); ++i) {
    //!         func(acc(i, j));
    //!     }
    //! }
    //! \endcode
    //!
    //! Below is the sample usage:
    //!
    //! \code{.cpp}
    //! int data = {1, 2, 3, 4, 5, 6};
    //! ConstArrayAccessor<int, 2> acc(2, 3, data);
    //! acc.forEach([](int elem) {
    //!     printf("%d\n", elem);
    //! });
    //! \endcode
    //!
    template <typename Callback>
    void forEach(Callback func) const;

    //!
    //! \brief Iterates the array and invoke given \p func for each index.
    //!
    //! This function iterates the array elements and invoke the callback
    //! function \p func. The callback function takes two parameters which are
    //! the (i, j) indices of the array. The order of execution will be the same
    //! as the nested for-loop below:
    //!
    //! \code{.cpp}
    //! int data = {1, 2, 3, 4, 5, 6};
    //! ConstArrayAccessor<int, 2> acc(2, 3, data);
    //! for (size_t j = 0; j < acc.height(); ++j) {
    //!     for (size_t i = 0; i < acc.width(); ++i) {
    //!         func(i, j);
    //!     }
    //! }
    //! \endcode
    //!
    //! Below is the sample usage:
    //!
    //! \code{.cpp}
    //! int data = {1, 2, 3, 4, 5, 6};
    //! ConstArrayAccessor<int, 2> acc(2, 3, data);
    //! acc.forEachIndex([&](size_t i, size_t j) {
    //!     acc(i, j) = 4.f * i + 7.f * j + 1.5f;
    //! });
    //! \endcode
    //!
    template <typename Callback>
    void forEachIndex(Callback func) const;

    //!
    //! \brief Iterates the array and invoke given \p func for each index in
    //!     parallel using multi-threading.
    //!
    //! This function iterates the array elements and invoke the callback
    //! function \p func in parallel using multi-threading. The callback
    //! function takes two parameters which are the (i, j) indices of the array.
    //! The order of execution will be non-deterministic since it runs in
    //! parallel. Below is the sample usage:
    //!
    //! \code{.cpp}
    //! int data = {1, 2, 3, 4, 5, 6};
    //! ConstArrayAccessor<int, 2> acc(2, 3, data);
    //! acc.parallelForEachIndex([&](size_t i, size_t j) {
    //!     acc(i, j) *= 2;
    //! });
    //! \endcode
    //!
    template <typename Callback>
    void parallelForEachIndex(Callback func) const;

    //! Returns the linear index of the given 2-D coordinate (pt.x, pt.y).
    size_t index(const Point2UI& pt) const;

    //! Returns the linear index of the given 2-D coordinate (i, j).
    size_t index(size_t i, size_t j) const;

    //! Returns the const reference to the i-th element.
    const T& operator[](size_t i) const;

    //! Returns the const reference to the element at (pt.x, pt.y).
    const T& operator()(const Point2UI& pt) const;

    //! Returns the const reference to the element at (i, j).
    const T& operator()(size_t i, size_t j) const;

 private:
    Size2 _size;
    const T* _data;
};

//! Type alias for 2-D const array accessor.
template <typename T>
using ConstArrayAccessor2 = ConstArrayAccessor<T, 2>;

}  // namespace jet

```


### (3) ArraySampler


***

<br>
<br>


# 4) Vector


<br>
<br>

jet 에서 Vector 클래스는 data container로서의 std::vector와는 의미하는 바가 조금 다르다. jet에서 Vector클래스는 수학적인 의미로서 백터에 가깝다. Vector 클래스에도 각 차원마다 Vector<T, N>이 존재하고 맴버함수는 우리가 백터를 이용할 때 유용한 함수들, 예를들어, 백터의 크기라던지 반사백터 등으로 이루어져있다.

<br>
<br>

```cpp
namespace jet {

//!
//! \brief 2-D vector class.
//!
//! This class defines simple 2-D vector data.
//!
//! \tparam T - Type of the element
//!
template <typename T>
class Vector<T, 2> final {
 public:
    static_assert(std::is_floating_point<T>::value, "Vector only can be instantiated with floating point types");

    //! X (or the first) component of the vector.
    T x;

    //! Y (or the second) component of the vector.
    T y;

    // MARK: Constructors

    //! Constructs default vector (0, 0).
    constexpr Vector() : x(0), y(0) {}

    //! Constructs vector with given parameters \p x_ and \p y_.
    constexpr Vector(T x_, T y_) : x(x_), y(y_) {}

    //! Constructs vector with initializer list.
    template <typename U>
    Vector(const std::initializer_list<U>& lst);

    //! Copy constructor.
    constexpr Vector(const Vector& v) : x(v.x), y(v.y) {}

    // MARK: Basic setters

    //! Set both x and y components to \p s.
    void set(T s);

    //! Set x and y components with given parameters.
    void set(T x, T y);

    //! Set x and y components with given initializer list.
    template <typename U>
    void set(const std::initializer_list<U>& lst);

    //! Set x and y with other vector \p pt.
    void set(const Vector& pt);

    //! Set both x and y to zero.
    void setZero();

    //! Normalizes this vector.
    void normalize();

    // MARK: Binary operations: new instance = this (+) v

    //! Computes this + (v, v).
    Vector add(T v) const;

    //! Computes this + (v.x, v.y).
    Vector add(const Vector& v) const;

    //! Computes this - (v, v).
    Vector sub(T v) const;

    //! Computes this - (v.x, v.y).
    Vector sub(const Vector& v) const;

    //! Computes this * (v, v).
    Vector mul(T v) const;

    //! Computes this * (v.x, v.y).
    Vector mul(const Vector& v) const;

    //! Computes this / (v, v).
    Vector div(T v) const;

    //! Computes this / (v.x, v.y).
    Vector div(const Vector& v) const;

    //! Computes dot product.
    T dot(const Vector& v) const;

    //! Computes cross product.
    T cross(const Vector& v) const;

    // MARK: Binary operations: new instance = v (+) this

    //! Computes (v, v) - this.
    Vector rsub(T v) const;

    //! Computes (v.x, v.y) - this.
    Vector rsub(const Vector& v) const;

    //! Computes (v, v) / this.
    Vector rdiv(T v) const;

    //! Computes (v.x, v.y) / this.
    Vector rdiv(const Vector& v) const;

    //! Computes \p v cross this.
    T rcross(const Vector& v) const;

    // MARK: Augmented operations: this (+)= v

    //! Computes this += (v, v).
    void iadd(T v);

    //! Computes this += (v.x, v.y).
    void iadd(const Vector& v);

    //! Computes this -= (v, v).
    void isub(T v);

    //! Computes this -= (v.x, v.y).
    void isub(const Vector& v);

    //! Computes this *= (v, v).
    void imul(T v);

    //! Computes this *= (v.x, v.y).
    void imul(const Vector& v);

    //! Computes this /= (v, v).
    void idiv(T v);

    //! Computes this /= (v.x, v.y).
    void idiv(const Vector& v);

    // MARK: Basic getters

    //! Returns const reference to the \p i -th element of the vector.
    const T& at(size_t i) const;

    //! Returns reference to the \p i -th element of the vector.
    T& at(size_t i);

    //! Returns the sum of all the components (i.e. x + y).
    T sum() const;

    //! Returns the average of all the components.
    T avg() const;

    //! Returns the minimum value among x and y.
    T min() const;

    //! Returns the maximum value among x and y.
    T max() const;

    //! Returns the absolute minimum value among x and y.
    T absmin() const;

    //! Returns the absolute maximum value among x and y.
    T absmax() const;

    //! Returns the index of the dominant axis.
    size_t dominantAxis() const;

    //! Returns the index of the subminant axis.
    size_t subminantAxis() const;

    //! Returns normalized vector.
    Vector normalized() const;

    //! Returns the length of the vector.
    T length() const;

    //! Returns the squared length of the vector.
    T lengthSquared() const;

    //! Returns the distance to the other vector.
    T distanceTo(const Vector& other) const;

    //! Returns the squared distance to the other vector.
    T distanceSquaredTo(const Vector& other) const;

    //! Returns the reflection vector to the surface with given surface normal.
    Vector reflected(const Vector& normal) const;

    //! Returns the projected vector to the surface with given surface normal.
    Vector projected(const Vector& normal) const;

    //! Returns the tangential vector for this vector.
    Vector tangential() const;

    //! Returns a vector with different value type.
    template <typename U>
    Vector<U, 2> castTo() const;

    //! Returns true if \p other is the same as this vector.
    bool isEqual(const Vector& other) const;

    //! Returns true if \p other is similar to this vector.
    bool isSimilar(const Vector& other, T epsilon = std::numeric_limits<T>::epsilon()) const;

    // MARK: Operators

    //! Returns reference to the \p i -th element of the vector.
    T& operator[](size_t i);

    //! Returns const reference to the \p i -th element of the vector.
    const T& operator[](size_t i) const;

    //! Set x and y components with given initializer list.
    template <typename U>
    Vector& operator=(const std::initializer_list<U>& lst);

    //! Set x and y with other vector \p pt.
    Vector& operator=(const Vector& v);

    //! Computes this += (v, v)
    Vector& operator+=(T v);

    //! Computes this += (v.x, v.y)
    Vector& operator+=(const Vector& v);

    //! Computes this -= (v, v)
    Vector& operator-=(T v);

    //! Computes this -= (v.x, v.y)
    Vector& operator-=(const Vector& v);

    //! Computes this *= (v, v)
    Vector& operator*=(T v);

    //! Computes this *= (v.x, v.y)
    Vector& operator*=(const Vector& v);

    //! Computes this /= (v, v)
    Vector& operator/=(T v);

    //! Computes this /= (v.x, v.y)
    Vector& operator/=(const Vector& v);

    //! Returns true if \p other is the same as this vector.
    bool operator==(const Vector& v) const;

    //! Returns true if \p other is the not same as this vector.
    bool operator!=(const Vector& v) const;
};

//! Type alias for two dimensional vector.
template <typename T>
using Vector2 = Vector<T, 2>;

//! Positive sign operator.
template <typename T>
Vector2<T> operator+(const Vector2<T>& a);

//! Negative sign operator.
template <typename T>
Vector2<T> operator-(const Vector2<T>& a);

//! Computes (a, a) + (b.x, b.y).
template <typename T>
Vector2<T> operator+(T a, const Vector2<T>& b);

//! Computes (a.x, a.y) + (b.x, b.y).
template <typename T>
Vector2<T> operator+(const Vector2<T>& a, const Vector2<T>& b);

//! Computes (a.x, a.y) - (b, b).
template <typename T>
Vector2<T> operator-(const Vector2<T>& a, T b);

//! Computes (a, a) - (b.x, b.y).
template <typename T>
Vector2<T> operator-(T a, const Vector2<T>& b);

//! Computes (a.x, a.y) - (b.x, b.y).
template <typename T>
Vector2<T> operator-(const Vector2<T>& a, const Vector2<T>& b);

//! Computes (a.x, a.y) * (b, b).
template <typename T>
Vector2<T> operator*(const Vector2<T>& a, T b);

//! Computes (a, a) * (b.x, b.y).
template <typename T>
Vector2<T> operator*(T a, const Vector2<T>& b);

//! Computes (a.x, a.y) * (b.x, b.y).
template <typename T>
Vector2<T> operator*(const Vector2<T>& a, const Vector2<T>& b);

//! Computes (a.x, a.y) / (b, b).
template <typename T>
Vector2<T> operator/(const Vector2<T>& a, T b);

//! Computes (a, a) / (b.x, b.y).
template <typename T>
Vector2<T> operator/(T a, const Vector2<T>& b);

//! Computes (a.x, a.y) / (b.x, b.y).
template <typename T>
Vector2<T> operator/(const Vector2<T>& a, const Vector2<T>& b);

//! Returns element-wise min vector: (min(a.x, b.x), min(a.y, b.y)).
template <typename T>
Vector2<T> min(const Vector2<T>& a, const Vector2<T>& b);

//! Returns element-wise max vector: (max(a.x, b.x), max(a.y, b.y)).
template <typename T>
Vector2<T> max(const Vector2<T>& a, const Vector2<T>& b);

//! Returns element-wise clamped vector.
template <typename T>
Vector2<T> clamp(const Vector2<T>& v, const Vector2<T>& low, const Vector2<T>& high);

//! Returns element-wise ceiled vector.
template <typename T>
Vector2<T> ceil(const Vector2<T>& a);

//! Returns element-wise floored vector.
template <typename T>
Vector2<T> floor(const Vector2<T>& a);

//! Float-type 2D vector.
typedef Vector2<float> Vector2F;

//! Double-type 2D vector.
typedef Vector2<double> Vector2D;

// MARK: Extensions

//! Returns float-type zero vector.
template <>
constexpr Vector2F zero<Vector2F>() {
    return Vector2F(0.f, 0.f);
}

//! Returns double-type zero vector.
template <>
constexpr Vector2D zero<Vector2D>() {
    return Vector2D(0.0, 0.0);
}

//! Returns the type of the value itself.
template <typename T>
struct ScalarType<Vector2<T>> {
    typedef T value;
};

//! Computes monotonic Catmull-Rom interpolation.
template <typename T>
Vector2<T> monotonicCatmullRom(const Vector2<T>& v0, const Vector2<T>& v1, const Vector2<T>& v2, const Vector2<T>& v3, T f);

}  // namespace jet
```

***

## 5) Ray

<br>
<br>

Ray 클래스는 Vector 클래스의 연장선에 있다. Vector클래스에 기준점 orgin이 포함된 형태이다.

<br>
<br>

```cpp
namespace jet {

//!
//! \brief      Class for 2-D ray.
//!
//! \tparam     T     The value type.
//!
template <typename T>
class Ray<T, 2> final {
 public:
    static_assert(std::is_floating_point<T>::value, "Ray only can be instantiated with floating point types");

    //! The origin of the ray.
    Vector2<T> origin;

    //! The direction of the ray.
    Vector2<T> direction;

    //! Constructs an empty ray that points (1, 0) from (0, 0).
    Ray();

    //! Constructs a ray with given origin and riection.
    Ray(const Vector2<T>& newOrigin, const Vector2<T>& newDirection);

    //! Copy constructor.
    Ray(const Ray& other);

    //! Returns a point on the ray at distance \p t.
    Vector2<T> pointAt(T t) const;
};

//! Type alias for 2-D ray.
template <typename T>
using Ray2 = Ray<T, 2>;

//! Float-type 2-D ray.
typedef Ray2<float> Ray2F;

//! Double-type 2-D ray.
typedef Ray2<double> Ray2D;

}  // namespace jet

```
