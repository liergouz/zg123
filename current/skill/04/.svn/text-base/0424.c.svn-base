
inherit SKILL;

// 函数：构造处理
void create() 
{ 
        set_number(0424);
        set_name( "金罡法咒" );
}

// 函数：能否特殊技
void can_perform( object me )
{
        __DIR__ "04241"->can_perform(me);
        __DIR__ "04242"->can_perform(me);
        __DIR__ "04243"->can_perform(me);
        __DIR__ "04244"->can_perform(me);
}

// 函数：删除特殊技
void remove_perform( object me )
{
        send_user( me, "%c%w%w", 0x50, 0xffff, 04241 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 04242 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 04243 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 04244 );        
}

// 函数：获取描述
string get_desc() 
{
        return "［金罡法咒］以群体攻击法术为主的技能。\n";
}
