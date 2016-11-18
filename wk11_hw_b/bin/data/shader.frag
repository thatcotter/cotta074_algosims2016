//translated and adapted from creation by silexars
//https://www.shadertoy.com/view/XsXXDn
#version 120

uniform vec2 resolution;
uniform float time;

void main( void ) {
    vec3 c;
    float l,z = time;
    for(int i = 0; i < 3; i++){
        vec2 p = gl_FragCoord.xy /resolution;
        vec2 uv = p;
        p-=.5;
		p.x*=resolution.x/resolution.y;
		z+=.99;
        l=length(p*2);
        uv+=p/l*(cos(z)+.5)*abs(cos(l*9.-z*1.));
        c[i] = .01/length(abs(mod(uv,.9)-.5));
    }

	gl_FragColor = vec4(c/l,time);
}