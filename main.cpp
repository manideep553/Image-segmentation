#include <opencv2/opencv.hpp>
#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>
#include<iterator>
#include <limits.h> 
#include <string.h> 
#include <queue> 

using namespace cv;
using namespace std;

	int elemarray[4];
	Mat o_image;
int* arrayElementFun(int** arrayIndex,int s,int row,int column)
{
	
//cout<<column<<"row"<<row<<endl;
	
	for(int i=0;i<4;i++)
	{
		elemarray[i];
	}
	int v=0;
	int rPixel,lPixel,bPixel,tPixel;
	
	int n=0;
	for(int i=0;i<row;i++ )
	{
		for(int j=0;j<column;j++ )
		{
			
		//	cout<<"this is array func"<<arrayIndex[i][j]<<endl;
	if(s ==arrayIndex[i][j])
	{			
		if(i==0&&j==0)
		{
		
		rPixel=arrayIndex[i][j+1];
		elemarray[n]=rPixel;
		n++;
		bPixel=arrayIndex[i+1][j];
		elemarray[n]=bPixel;
		
		}
		
		//case2
		if(i==0&&j>0&&j<column)
		{
		
		rPixel=arrayIndex[i][j+1];
		elemarray[n]=rPixel;
		n++;
		//cout<<rPixel<<endl;
		bPixel=arrayIndex[i+1][j];
		elemarray[n]=bPixel;
		//cout<<bPixel<<endl;
		n++;
		lPixel=arrayIndex[i][j-1];
		elemarray[n]=lPixel;
		//cout<<lPixel<<endl;
		n++;
		
			}
		
		//case3
		if(i==0&&j==column)
		{
		
		lPixel=arrayIndex[i][j-1];
		elemarray[n]=lPixel;
		n++;
		bPixel=arrayIndex[i+1][j];
		elemarray[n]=bPixel;
		n++;
		}
		//case4
		if(j==0&&i>0&&i<column)
		{
	
		rPixel=arrayIndex[i][j+1];
		elemarray[n]=rPixel;
		n++;
		bPixel=arrayIndex[i+1][j];
		elemarray[n]=bPixel;
		
		}
		//case6
		if(j==column && i>0 && i<row)
		{
		
		bPixel=arrayIndex[i+1][j];
		elemarray[n]=bPixel;
		n++;
		lPixel=arrayIndex[i][j-1];
		elemarray[n]=lPixel;
		n++;
		tPixel=arrayIndex[i-1][j];
		elemarray[n]=tPixel;
		
		}
		//case7
		if(j==0&&i==row)
		{
		
		rPixel=arrayIndex[i][j+1];
		elemarray[n]=rPixel;
		n++;
		tPixel=arrayIndex[i-1][j];
		elemarray[n]=tPixel;
		}
		//case8
		if(j>0&&i==row&&j<column)
		{
		rPixel=arrayIndex[i][j+1];
		elemarray[n]=rPixel;
		n++;
		lPixel=arrayIndex[i][j-1];
		elemarray[n]=lPixel;
		n++;
		tPixel=arrayIndex[i-1][j];
		elemarray[n]=tPixel;
	}
		//case9
		if(i==row&&j==column)
		{
		
		lPixel=arrayIndex[i][j-1];
		elemarray[n]=lPixel;
		n++;
		tPixel=arrayIndex[i-1][j];
		elemarray[n]=tPixel;
		}
		//case5
		if(i>0&&j>0&&i<column&&j<column)
		{
		
		rPixel=arrayIndex[i][j+1];
		elemarray[n]=rPixel;
		n++;
		bPixel=arrayIndex[i+1][j];
		elemarray[n]=bPixel;
		n++;
		lPixel=arrayIndex[i][j-1];
		elemarray[n]=lPixel;
		n++;
		tPixel=arrayIndex[i-1][j];
		elemarray[n]=tPixel;
		}
		//cout<<"this is array func"<<arrayIndex[i][j]<<endl;
		i=row;
		j=column;
		
		}
		}

	}
	return elemarray;
}

//bfs(rGraph,arraycomp,324,32760,row,column,arrayIndex)
void  bfs(Mat rGraph,Mat arraycomp, long sx, long row,int column,int **adjIndex,Mat o_image,long *foregroundIndex,int l,int color)
{
//	row--;
//	column--;
	long V = row*column;
	// Create a visited array and mark all vertices as not visited 
	bool *visit;
	visit = new bool[V];
	for(long x=0;x<V;x++)
		visit[x]=false;
	
	int s=foregroundIndex[0];
//	int fi=foregroundIndex.size();
	int sex=sizeof(foregroundIndex);
	int fi;
	fi=sex/7;
	//cout<<sex<<"hey whats up"<<endl;
	int *parent; // This array is filled by BFS and to store path 
	parent = new int[V];
	// Create a queue, enqueue source vertex and mark source vertex 
	// as visited 
	int number=5;
	int *arrayElement;
	
	queue <int> q;
	long si;
	for(int i=0;i<l;i++)
	{
		si=foregroundIndex[i];
	//	cout<<si<<endl<<"hello";
		visit[si] = true;
		
			q.push(si);
	}

parent[s] = -1;
	int x = q.front();
	//cout <<"hello swq"<< x << endl;
	long v;
	//cout<<"bfs is running";
	
	// Stan	dard BFS Loop 
	while (!q.empty())
	{
		long u = q.front();
		q.pop();
			if(u==1)
				{
				//cout<<u<<endl;	
				}
		
				else
				{
			//	cout<<u;
				for(int i=0;i<=row;i++)
					{
						for(int j=0;j<=column;j++)
						{
						if(u ==adjIndex[i][j])
						{
						//cout<<"i"<<"j"<<i<<j<<endl;
						o_image.at<uchar>(i,j)=color;
							}	
						
						}
					}
				arrayElement=arrayElementFun(adjIndex,u,row, column);	
	//arrayElement = arrayElem(adjIndex,s,row,column);
				for (int vi = 0; vi < 4; vi++)
				{
				v=arrayElement[vi];
//	cout<<"get values"<<v;
	/*	for (int vi = 0; vi < arrayElement.size(); vi++)
		{
		
	*/
			if (visit[v] == false && rGraph.at<int>(u,v) > 0)
			{
			//	cout<<"-"<<v<<endl;	
				q.push(v);
				parent[v] = u;
				visit[v] = true;
			}
		}
	}
	} 
	// If we reached sink in BFS starting from source, then return 
	// true, else false 
//	return (visited[t] == true);

}

void assignvalues(int** weightIndex,int **arrayIndex,int max,int row,int column,Mat arraycomp,Mat o_image,long *foregroundIndex,long *backgroundIndex,int xj,int lx)
{
	
	
	row--;
	column--;
	int w=0;
	int wPixel=0,wlPixel=0,wrPixel=0,wtPixel=0,wbPixel=0;
	int Pixel=0,lPixel=0,rPixel=0,tPixel=0,bPixel=0;
	int l,r,t,b;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<column;j++)
		{
			l=0;
			r=0;
			t=0;
			b=0;
		//case1	
		if(i==0&&j==0)
		{
		wPixel=weightIndex[i][j];
		wrPixel=weightIndex[i][j+1];
		wbPixel=weightIndex[i+1][j];
	
		Pixel=arrayIndex[i][j];
		rPixel=arrayIndex[i][j+1];
		bPixel=arrayIndex[i+1][j];
	
		//p1-p2
		if(wPixel==wrPixel)
		{
		r=2;
		}
		arraycomp.at<int>(Pixel,rPixel)=r;
		
		if(wPixel==wbPixel)
		{
			b=2;
		}
		arraycomp.at<int>(Pixel,bPixel)=b;
		}
		
		//case2
		if(i==0&&j>0&&j<column)
		{
		wPixel=weightIndex[i][j];
		wlPixel=weightIndex[i][j-1];
		wrPixel=weightIndex[i][j+1];
		wbPixel=weightIndex[i+1][j];

	
		Pixel=arrayIndex[i][j];
		rPixel=arrayIndex[i][j+1];
		bPixel=arrayIndex[i+1][j];
		lPixel=arrayIndex[i][j-1];
		
		if(wPixel==wlPixel)
		{
			l=2;
		}
		arraycomp.at<int>(Pixel,lPixel)=l;
		if(wPixel==wrPixel)
		{
  			r=2;
		}
		arraycomp.at<int>(Pixel,rPixel)=r;
		if(wPixel==bPixel)
		{
			b=2;
		}
		arraycomp.at<int>(Pixel,bPixel)=b;
		}
		
		//case3
		if(i==0&&j==column)
		{
		wPixel=weightIndex[i][j];
		wlPixel=weightIndex[i][j-1];
		wbPixel=weightIndex[i+1][j];
		
		
		Pixel=arrayIndex[i][j];
		lPixel=arrayIndex[i][j-1];
		bPixel=arrayIndex[i+1][j];
		if(wPixel==wlPixel)
		{
			l=2;
		}
		arraycomp.at<int>(Pixel,lPixel)=l;
		
		if(wPixel==wbPixel)
		{
			b=2;
		}
		arraycomp.at<int>(Pixel,bPixel)=b;
		}
		//case4
		
		if(j==0&&i>0&&i<column)
		{
		wPixel=weightIndex[i][j];
		wrPixel=weightIndex[i][j+1];
		wbPixel=weightIndex[i+1][j];
		
		Pixel=arrayIndex[i][j];
		rPixel=arrayIndex[i][j+1];
		bPixel=arrayIndex[i+1][j];
		if(wPixel==wrPixel)
		{
			r=2;
		}
		arraycomp.at<int>(Pixel,rPixel)=r;
		if(wPixel==wbPixel)
		{
			b=2;
		}
		arraycomp.at<int>(Pixel,bPixel)=b;
		}
		//case6
		if(j==column && i>0 && i<row)
		{
		wPixel=weightIndex[i][j];
		wlPixel=weightIndex[i][j-1];
		wbPixel=weightIndex[i+1][j];
		wtPixel=weightIndex[i-1][j];
		
		Pixel=arrayIndex[i][j];
		bPixel=arrayIndex[i+1][j];
		lPixel=arrayIndex[i][j-1];
		tPixel=arrayIndex[i-1][j];
		if(wPixel==wlPixel)
		{
			l=2;
		}
		arraycomp.at<int>(Pixel,lPixel)=l;
		
		if(wPixel==wbPixel)
		{
			b=2;
		}
		arraycomp.at<int>(Pixel,bPixel)=b;
		if(wPixel==wtPixel)
		{
			t=2;
		}
		arraycomp.at<int>(Pixel,tPixel)=t;
		}
		//case7
		if(j==0&&i==row)
		{
		wPixel=weightIndex[i][j];
		wrPixel=weightIndex[i][j+1];
		wtPixel=weightIndex[i-1][j];
		
		Pixel=arrayIndex[i][j];
		rPixel=arrayIndex[i][j+1];
		tPixel=arrayIndex[i-1][j];
		if(wPixel==wlPixel)
		{
			l=2;
		}
		arraycomp.at<int>(Pixel,lPixel)=l;
		if(wPixel==wrPixel)
		{
			r=2;
		}
		arraycomp.at<int>(Pixel,rPixel)=r;
		}
		//case8
		if(j>0&&i==row&&j<column)
		{
		wPixel=weightIndex[i][j];
		wrPixel=weightIndex[i][j+1];
		wtPixel=weightIndex[i-1][j];
		wlPixel=weightIndex[i][j-1];
		
		Pixel=arrayIndex[i][j];
		rPixel=arrayIndex[i][j+1];
		lPixel=arrayIndex[i][j-1];
		tPixel=arrayIndex[i-1][j];
		if(wPixel==wlPixel)
		{
			l=2;
		}
		arraycomp.at<int>(Pixel,lPixel)=l;
		
		if(wPixel==wrPixel)
		{
			r=2;
		}
		arraycomp.at<int>(Pixel,rPixel)=r;
		
		if(wPixel==wtPixel)
		{
			t=2;
		}
		arraycomp.at<int>(Pixel,tPixel)=max-(wPixel+wtPixel);
		}
		
		//case9
		if(i==row&&j==column)
		{
		wPixel=weightIndex[i][j];
		wtPixel=weightIndex[i-1][j];
		wlPixel=weightIndex[i][j-1];	
		
		Pixel=arrayIndex[i][j];
		lPixel=arrayIndex[i][j-1];
		tPixel=arrayIndex[i-1][j];
		if(wPixel==wlPixel)
		{
			l=2;
		}
		arraycomp.at<int>(Pixel,lPixel)=l;
		if(wPixel==wtPixel)
		{
			t=2;
		}
		arraycomp.at<int>(Pixel,tPixel)=t;
		}
		//case5
		if(i>0&&j>0&&i<column&&j<column)
		{
		wPixel=weightIndex[i][j];
		wrPixel=weightIndex[i][j+1];
		wtPixel=weightIndex[i-1][j];
		wlPixel=weightIndex[i][j-1];
		wbPixel=weightIndex[i+1][j];
		
		Pixel=arrayIndex[i][j];
		rPixel=arrayIndex[i][j+1];
		bPixel=arrayIndex[i+1][j];
		lPixel=arrayIndex[i][j-1];
		tPixel=arrayIndex[i-1][j];
		
		if(wPixel==wlPixel)
		{
			l=2;
		}
		arraycomp.at<int>(Pixel,lPixel)=l;
	if(wPixel==wrPixel)
		{
			r=2;
		}
		arraycomp.at<int>(Pixel,rPixel)=r;
		if(wPixel==wtPixel)
		{
			t=2;
		}
		arraycomp.at<int>(Pixel,tPixel)=t;
		
		if(wPixel==wbPixel)
		{
			b=2;
		}
		arraycomp.at<int>(Pixel,bPixel)=b;
		
		                   
		}
	}
}

//int u=180,v,wi;
int u=0;
Mat rGraph;
rGraph=arraycomp;
u=rGraph.at<int>(180,181);
int black=0;
int white=255;

bfs(rGraph,arraycomp,1324,row,column,arrayIndex,o_image,backgroundIndex,xj,white);
bfs(rGraph,arraycomp,1324,row,column,arrayIndex,o_image,foregroundIndex,lx,black);
}

int main( int argc, char** argv )
{
  Mat gray;
  Mat src, src_gray;
  Mat grad;
  
  
  int scale = 1;
  int delta = 0;
  int ddepth = CV_16S;

    if(argc!=4)
	{
        cout<<"Usage: ../seg input_image initialization_file output_mask"<<endl;
        return -1;
    }

    Mat in_image;
    in_image = imread(argv[1]/*, CV_LOAD_IMAGE_COLOR*/);
   
    if(!in_image.data)
    {
        cout<<"Could not load input image!!!"<<endl;
        return -1;
    }

    if(in_image.channels()!=3){
        cout<<"Image does not have 3 channels!!! "<<in_image.depth()<<endl;
        return -1;
    }
    
    ifstream f(argv[2]);
    if(!f)
	{
        cout<<"Could not load initial mask file!!!"<<endl;
        return -1;
    }
	
    int width = in_image.cols;
    int height = in_image.rows;
    int colomns = width;
    int rows =height;
	long sizeofgraph=rows*colomns;
	long count=0;

	int **arrayIndex=new int*[rows];
     for(int i=0;i<rows;i++)
	 {
		arrayIndex[i]=new int[colomns];
	 }
	 
	 int **weightIndex=new int*[rows];
     for(int i=0;i<rows;i++)
	 {
		weightIndex[i]=new int[colomns];
	 }
	 
	
 //	cout<<"total count"<<count<<endl;
    
    int n;
    f>>n;
    
    
    int **foreground=new int*[n];
	for(int i=0;i<n;i++)
	 {
		foreground[i]=new int[3];
	 }
	
	long *backgroundIndex;
		backgroundIndex=new long[n];

	
	long *foregroundIndex;
		foregroundIndex=new long[n];

    int **background=new int*[n];
    for(int i=0;i<n;i++)
	 {
	  background[i]=new int[3];
	 }
	 
	 
	     	// Convert it to gray
        cvtColor(in_image,gray,CV_BGR2GRAY);
  
 		 //Generate grad_x and grad_y
 		Mat grad_x, grad_y;
  		Mat abs_grad_x, abs_grad_y;

  		/// Gradient X
  		//Scharr( src_gray, grad_x, ddepth, 1, 0, scale, delta, BORDER_DEFAULT );
  		Sobel( gray, grad_x, ddepth, 1, 0, 3, scale, delta, BORDER_DEFAULT );
  		convertScaleAbs( grad_x, abs_grad_x );

		// Gradient Y
  		//Scharr( src_gray, grad_y, ddepth, 0, 1, scale, delta, BORDER_DEFAULT );
  		Sobel(gray, grad_y, ddepth, 0, 1, 3, scale, delta, BORDER_DEFAULT );
  		convertScaleAbs( grad_y, abs_grad_y );

  		/// Total Gradient (approximate)
  		addWeighted( abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad );
  		// imshow( "show grad pixels", grad );
		//int intensity;
	//	cout<<rows<<endl;
	//	cout<<colomns<<endl;

//cout<<"hello"<<endl;
for(int i=0;i<rows;i++)
 {
	 for(int j=0;j<colomns;j++)
	 {
		weightIndex[i][j]=(int)grad.at<uchar>(i,j);		
	}
	//cout<<endl;
}
for(int i=0;i<rows;i++)
 {
	 for(int j=0;j<colomns;j++)
	 {
	 	count++;
		arrayIndex[i][j]=count;
			
	}
	//cout<<endl;
}    
    // get the initil pixels
    // t is the foreground or background determination value of the image
	int xj=0,xh=0,fore,l=0;
        for(int i=0;i<n;++i)
		{
    	    int xcordinate, ycordinate, t;
        	f>>ycordinate>>xcordinate>>t;
    		int k=0;
		 
        if(xcordinate<0 || xcordinate>=width || ycordinate<0 || ycordinate>=height)
		{
			
        }


			if(t==1)
				{
				  //cout<<"x "<<xcordinate<<" y"<<ycordinate<<t<<endl;
				backgroundIndex[xj]=arrayIndex[xcordinate][ycordinate];
				xj++;
						}
		    			if(t==0)
						{
							  //cout<<"x "<<xcordinate<<" y"<<ycordinate<<t<<endl;
						foregroundIndex[l]=arrayIndex[xcordinate][ycordinate];
						//cout<<foregroundIndex[l]<<endl;
						l++;
						
						}
					}
				

long xy=rows*colomns;
Mat arraycomp(xy,xy,CV_8U);
int max=1234;
//cout<<arraycomp.rows<<endl;

o_image=grad.clone();
 assignvalues(weightIndex,arrayIndex,max,rows,colomns,arraycomp,o_image,foregroundIndex,backgroundIndex,xj,l);

    namedWindow( "Original image", WINDOW_AUTOSIZE );
    namedWindow( "Show Marked Pixels", WINDOW_AUTOSIZE );
     imshow( "Original image", in_image );
    imshow( "Show Marked Pixels", o_image );
    
 imwrite( argv[3], o_image);
    waitKey(0);    
	return 0;
}