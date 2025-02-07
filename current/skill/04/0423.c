
inherit SKILL;

// 函数：构造处理
void create() 
{ 
        set_number(0423);
        set_name( "金仙符咒" );
}

// 函数：能否特殊技
void can_perform( object me )
{
        __DIR__ "04231"->can_perform(me);
        __DIR__ "04232"->can_perform(me);
        __DIR__ "04233"->can_perform(me);
        __DIR__ "04234"->can_perform(me);
        __DIR__ "04235"->can_perform(me);
        __DIR__ "04236"->can_perform(me);
        __DIR__ "04237"->can_perform(me);
}

// 函数：删除特殊技
void remove_perform( object me )
{
        send_user( me, "%c%w%w", 0x50, 0xffff, 04231 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 04232 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 04233 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 04234 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 04235 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 04236 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 04237 );
}

// 函数：获取描述
string get_desc() 
{
        return "［金仙符咒］昆仑山独创的神法，可操纵天雷与寒冰的力量。\n";
}
