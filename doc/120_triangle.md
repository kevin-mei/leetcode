**从上到下，上面的元素只能访问相邻的下一行的元素**， 另a[i][j]代表第i行，第j列元素可以得到的最短路径，从上往下访问，最后访问元素是triangle[i][j],能访问到它的triangle[i-1][j-1] 和triangle[i-1][j]两个元素，以这两个元素为终点的最短路径为a[i-1][j-1] 和a[i-1][j]；要求a[i][j] ，即求a[i-1][j-1] 和a[i-1][j]的最小值加上triangle[i][j]的值即可，这就得到了状态方程

a[i][j] = min(a[i-1][j-1],a[i-1][j])+triangle[i][j];

最后要求整个树的最短路径，也就是求它的a[i]行的最小元素值即可
