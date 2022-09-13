#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdio.h>



//device code, ran by GPU
__global__ void hello_cuda() {
	printf("threadIdx.x = %d, threadIdx.y = %d, threadIdx.z = %d \n", threadIdx.x, threadIdx.y, threadIdx.z);

}
//host code, ran by CPU
int main()
{
	int nx, ny;
	nx = 16;
	ny = 16;

	dim3 threadsPerBlock(16, 16); //grid
	dim3 numOfBlocks(nx / threadsPerBlock.x , ny / threadsPerBlock.y); //block
	hello_cuda <<< numOfBlocks, threadsPerBlock>>> ();
	

	cudaDeviceSynchronize();
	cudaDeviceReset();
	return 0;
}
