
inherit SKILL;

// 函数：构造处理
void create() 
{ 
        set_number(0348);
        set_name( "兵法" );
}

// 函数：能否特殊技
void can_perform( object me )
{
        __DIR__ "03481"->can_perform(me);
        __DIR__ "03483"->can_perform(me);
        __DIR__ "03484"->can_perform(me);
        __DIR__ "03485"->can_perform(me);
        
}

// 函数：删除特殊技
void remove_perform( object me )
{
        send_user( me, "%c%w%w", 0x50, 0xffff, 03481 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 03483 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 03484 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 03485 );
}

// 函数：重计属性
void recount_char( object me ) { USER_ENERGY_D->count_dp(me); }

// 函数：获取描述
string get_desc() 
{
        return "［兵法］禁卫军技能，可掌握更多实战的技巧，能提升防御力，每级提升0.6点。通过战斗可不断补充元气。\n";
}
