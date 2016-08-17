uniform sampler2DRect u_image;
//uniform sampler2DRect img2;

uniform float time;
uniform float amp;
uniform float ampY;

uniform float wavelength;
uniform vec2 res;

void main(){
    vec2 tc = gl_TexCoord[0].st;
    vec2 tc2 = tc;
    
    //    vec4 input0 = texture2DRect(u_image,tc + modCoord);
    //    vec2 modCoord = vec2(0.2,0.0);

    //      tc2.x = clamp(tc2.x, 626.0,9000.0);
   
    tc.x = floor(tc.x*amp)/amp;
//    tc.y = clamp(tc.y, res.y/3.5, res.y - res.y/2.5);
    tc.x = clamp(tc.x, res.x/2.5, res.x - res.x/2.5);
     vec2 modCoord = vec2(floor(tan(time + tc.x*amp)/wavelength), 0.0);
    
    
//    tc.y = floor(tc.y*ampY)/ampY;

    vec4 input0 = texture2DRect(u_image, tc + modCoord ) ;//* (1.0 - gl_TexCoord[0].s / 834.0);
    //    vec4 input1 = texture2DRect(img2, tc2 ) ;//* ( gl_TexCoord[0].s / 834.0);
    //    input0.r = floor(input0.r*wavelength)/wavelength;
    //    if(  gl_TexCoord[0].s / 834.0 < 0.5){
    gl_FragColor =  input0 ;
    //    } else {
    //        gl_FragColor = input1;
    //    }
    gl_FragColor.a = 1.0;
}