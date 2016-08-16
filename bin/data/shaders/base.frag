uniform sampler2DRect u_image;


void main(){

    vec4 input0 = texture2DRect(u_image,gl_TexCoord[0].st);

    gl_FragColor = input0;
}