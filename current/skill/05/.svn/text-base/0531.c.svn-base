
inherit SKILL;

// 函数：构造处理
void create() 
{ 
        set_number(0531);
        set_name( "迷魂诀" );
}

// 函数：能否特殊技
void can_perform( object me )
{
	__DIR__ "05310"->can_perform(me);
        __DIR__ "05311"->can_perform(me);
        __DIR__ "05312"->can_perform(me);
        __DIR__ "05313"->can_perform(me);
        __DIR__ "05314"->can_perform(me);        
        __DIR__ "05315"->can_perform(me);        
}

// 函数：重计属性
void recount_char( object me ) { USER_ENERGY_D->count_hit_rate(me); }

// 函数：删除特殊技
void remove_perform( object me )
{
        send_user( me, "%c%w%w", 0x50, 0xffff, 05310 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 05311 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 05312 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 05313 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 05314 );             
}

// 函数：获取描述
string get_desc() 
{
        return "［迷魂诀］云梦泽的特殊技法，可迷魂怪物为玩家所用。且每级可追加0.05％的法术暴击效果。\n";
}
