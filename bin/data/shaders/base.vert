//varying vec2 texcoord0;


void main()
{
    // perform standard transform on vertex
//    gl_Position = ftransform();
    gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
    gl_TexCoord[0] = gl_MultiTexCoord0;
    // transform texcoords
//    texcoord0 = vec2(gl_TextureMatrix[0] * gl_MultiTexCoord0);   
}