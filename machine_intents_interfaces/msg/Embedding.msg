bool    is_bigendian # Is this data bigendian?
uint32  point_step   # Length of a point in bytes
uint32  row_step     # Length of a row in bytes
float64[] data         # Actual point data, size is (row_step*height)

string comparison_type # Either cosine or distance