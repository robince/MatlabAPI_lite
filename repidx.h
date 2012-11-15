#define REPIDX(arr, idx, N ) REPIDX_##N( arr, idx )    
#define REPIDX_0(arr,idx) arr
#define REPIDX_1(arr,idx) arr(idx)
#define REPIDX_2(arr,idx) arr(idx,idx)
#define REPIDX_3(arr,idx) arr(idx,idx,idx)
#define REPIDX_4(arr,idx) arr(idx,idx,idx,idx)
#define REPIDX_5(arr,idx) arr(idx,idx,idx,idx,idx)
#define REPIDX_6(arr,idx) arr(idx,idx,idx,idx,idx,idx)
#define REPIDX_7(arr,idx) arr(idx,idx,idx,idx,idx,idx,idx)

