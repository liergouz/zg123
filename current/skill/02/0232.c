
inherit SKILL;

// 函数：构造处理
void create() 
{ 
        set_number(0232);
        set_name( "剑法格挡" );
}

// 函数：能否特殊技
void can_perform( object me )
{
        __DIR__ "02321"->can_perform(me);
}

// 函数：删除特殊技
void remove_perform( object me )
{
        send_user( me, "%c%w%w", 0x50, 0xffff, 02321 );
}

// 函数：重计属性
void recount_char( object me ) { USER_ENERGY_D->count_dp(me); }

// 函数：获取描述
string get_desc() 
{
        return "［剑法格挡］提升使用剑的防御力，每级提升 1.2 点\n";
}
