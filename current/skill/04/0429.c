
inherit SKILL;

// 函数：构造处理
void create() 
{ 
        set_number(0429);
        set_name( "龙游四海" );
}

// 函数：能否特殊技
void can_perform( object me )
{
        __DIR__ "04291"->can_perform(me);
}

// 函数：删除特殊技
void remove_perform( object me )
{
        send_user( me, "%c%w%w", 0x50, 0xffff, 04291 );
}

// 函数：获取描述
string get_desc() 
{
        return "［龙游四海］快速移动到其他人身边，对方法力越低成功率越高\n";
}
