uniform sampler2DRect u_image;
uniform sampler2DRect img2;

uniform float time;
uniform float amp;
uniform float wavelength;
void main(){
    vec2 tc = gl_TexCoord[0].st;
    vec2 tc2 = tc;
    
    vec2 modCoord = vec2(0.0,sin(time + tc.y*amp)*wavelength);
//    vec4 input0 = texture2DRect(u_image,tc + modCoord);
//    vec2 modCoord = vec2(0.2,0.0);
   
      tc.x = clamp(tc.x, 0.0,208.0);
      tc2.x = clamp(tc2.x, 626.0,9000.0);
//    tc.x = floor(tc.x*amp)/amp;
    
    
    
    vec4 input0 = texture2DRect(u_image, tc ) ;//* (1.0 - gl_TexCoord[0].s / 834.0);
    vec4 input1 = texture2DRect(img2, tc2 ) ;//* ( gl_TexCoord[0].s / 834.0);
//    input0.r = floor(input0.r*wavelength)/wavelength;
    if(  gl_TexCoord[0].s / 834.0 < 0.5){
    gl_FragColor =  input0 ;
    } else {
        gl_FragColor = input1;
    }
    gl_FragColor.a = 1.0;
}