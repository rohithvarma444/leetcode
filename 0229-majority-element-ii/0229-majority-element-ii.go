func majorityElement(nums []int) []int {
    n := len(nums)
    cnt1, cnt2 := 0, 0
    var elem1, elem2 int
    elem1, elem2 = 1e9, 1e9 

    for i := 0; i < n; i++ {
        if nums[i] == elem1 {
            cnt1++
        } else if nums[i] == elem2 {
            cnt2++
        } else if cnt1 == 0 {
            elem1 = nums[i]
            cnt1 = 1
        } else if cnt2 == 0 {
            elem2 = nums[i]
            cnt2 = 1
        } else {
            cnt1--
            cnt2--
        }
    }

    cnt1, cnt2 = 0, 0

    for i := 0; i < n; i++ {
        if nums[i] == elem1 {
            cnt1++
        } else if nums[i] == elem2 {
            cnt2++
        }
    }

    result := []int{}
    if cnt1 > n/3 {
        result = append(result, elem1)
    }
    if cnt2 > n/3 {
        result = append(result, elem2)
    }

    return result
}