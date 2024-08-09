#include <iostream>
#include <vector>
#include <stdexcept>

template<typename T>
class Heap {
private:
    std::vector<T> heap;
    bool isMinHeap;
    void heapifyUp(int index) {
        if (index && compare(heap[parent(index)], heap[index])) {
            std::swap(heap[index], heap[parent(index)]);
            heapifyUp(parent(index));
        }
    }
    void heapifyDown(int index) {
        int left = leftChild(index);
        int right = rightChild(index);
        int smallestLargest = index;
        if (left < size() && compare(heap[smallestLargest], heap[left]))
            smallestLargest = left;

        if (right < size() && compare(heap[smallestLargest], heap[right]))
            smallestLargest = right;

        if (smallestLargest != index) {
            std::swap(heap[index], heap[smallestLargest]);
            heapifyDown(smallestLargest);
        }
    }

    bool compare(const T& a, const T& b) const {
        return isMinHeap ? a > b : a < b;
    }

    int parent(int i) const { return (i - 1) / 2; }
    int leftChild(int i) const { return (2 * i + 1); }
    int rightChild(int i) const { return (2 * i + 2); }

public:
    Heap(bool minHeap = false) : isMinHeap(minHeap) {}
    int size() const {
        return heap.size();
    }
    bool isEmpty() const {
        return size() == 0;
    }
    void insert(const T& element) {
        heap.push_back(element);
        heapifyUp(size() - 1);
    }

    T getTop() const {
        if (isEmpty())
            throw std::runtime_error("Heap is empty");
        return heap.front();
    }
    T extractTop() {
        if (isEmpty())
            throw std::runtime_error("Heap is empty");

        T topElement = heap.front();
        heap.front() = heap.back();
        heap.pop_back();

        if (!isEmpty())
            heapifyDown(0);

        return topElement;
    }
    void printHeap() const {
        for (int i = 0; i < size(); ++i) {
            std::cout << heap[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
       std::vector<int>v{10,19,2,7,8,11,0};
         Heap<int>h(false);
          for(int i:v)
          h.insert(i);

           for(auto it=v.begin();it<v.end();++it)
            *it=h.extractTop();

            for(int i:v)
           std::cout<<i<<"  ";
    return 0;
}
