var MedianFinder = function () {
  this.arr = [];
};

/**
 * @param {number} num
 * @return {void}
 */
MedianFinder.prototype.addNum = function (num) {
  this.arr.push(num);
  this.arr = this.arr.sort();
};

/**
 * @return {number}
 */
MedianFinder.prototype.findMedian = function () {
  const size = this.arr.length;
  if (size % 2 != 0) {
    // 返回中间的数字
    const middleIndex = size / 2;
    return this.arr[middleIndex];
  } else {
    // 返回中间两个数字的平均值。
    const afterIndex = size / 2;
    const beforeIndex = afterIndex - 1;
    return this.arr[afterIndex] + this.arr[beforeIndex];
  }
};
