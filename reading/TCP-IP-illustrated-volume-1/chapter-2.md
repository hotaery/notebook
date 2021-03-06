## 第2章 Internet地址结构
+ IP地址结构
    - IP地址分为IPv4和IPv6，IPv4总共32字节，IPv6总共128字节
    - IP地址包含两个部分，网络号和主机号，前者用于公共网络路由，后者用于确定同一网络中的哪台主机或者那个网络接口
+ 子网
    - 通过给站点分配某个传统的IP地址空间，站点管理员通过给边界路由器分配子网掩码进一步将IP地址空间分成多个部分
    - 可变长度子网掩码可以将IP地址空间划分长多个不同数量的地址空间
+ 单播，广播，组播，任播
    - 单播：一个网络接口和另外一个网络接口通信
    - 广播：一个网络接口对所有网络接口通信
    - 组播：一个网路接口对一组网络接口通信
    - 任播：单播地址，可以根据该地址确定不同网络中具有相同服务功能的主机
+ CIDR（无类别域间路由）和聚合
    - 聚合是为了减少路由器需要存储的路由条目
    - 路由器根据IP地址最长前缀进行路由
+ IP地址分类
    - IPv4地址分类
        1. 主机部分为1表示是同一个子网的广播地址，通过将目的IP设为该地址，IP协议将会将该数据包发到子网内所有主机
        2. 255.255.255.255是一个特殊的广播地址，使用该地址作为目的IP的IP数据报将不会被路由转发，也就是只会在二层链路内被转发，如DHCP在发现DHCP服务时发送的数据报
        3. 0.0.0.0，当一台主机还没有分配IP时将会使用该地址作为发送地址，比如DHCP在动态获取IP时发送的数据报
        4. 专用网络，专用网络只会在同一个局域网内进行转发，不会被边界路由器转发，除非边界路由器配置了NAT功能
        5. 环回地址，本机进行服务程序测试
        6. 链路地址，只会在二层链路内进行转发，不会被IP协议转发，比如当动态获取IP失败时，将会给接口默认分配一个特殊前缀的地址用于同一链路内进行通信
        7. 组播地址
    - IPv6地址分类
        1. 本地环回地址
        2. 未指定地址，类似IPv4<0.0.0.0>
        3. 本地链路地址，类似IPv4链路地址
        4. 组播地址


## 参考链接
+ [理解IPv6地址分类](https://blog.51cto.com/7658423/1335939)