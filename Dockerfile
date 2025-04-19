FROM yg397/openresty-thrift:xenial

# install curl & lua, then download the Thrift.lua runtime
RUN apt-get update \
  && apt-get install -y curl lua5.1 \
  && rm -rf /var/lib/apt/lists/* \
  && mkdir -p /usr/local/openresty/lualib \
  && curl -sfL https://raw.githubusercontent.com/apache/thrift/master/lib/lua/Thrift.lua \
    -o /usr/local/openresty/lualib/thrift.lua

# bring in your generated lua stubs
COPY gen-lua /gen-lua

# bring in your Lua scripts
COPY lua-scripts /usr/local/openresty/nginx/lua-scripts

# put your custom nginx.conf in place
COPY conf/nginx.conf /usr/local/openresty/nginx/conf/nginx.conf

WORKDIR /usr/local/openresty/nginx
CMD ["openresty", "-g", "daemon off;"]
