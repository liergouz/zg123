
inherit SKILL;

// 函数：基本技能
int is_basic_skill() { return 1; }

// 函数：构造处理
void create() 
{ 
        set_number(0131);
        set_name( "基本剑法" );
}

// 函数：能否特殊技
void can_perform( object me )
{
}

// 函数：删除特殊技
void remove_perform( object me )
{
        send_user( me, "%c%w%w", 0x50, 0xffff, 01311 );
}

// 函数：重计属性
void recount_char( object me ) { USER_ENERGY_D->count_cp(me); }

// 函数：获取描述
string get_desc() 
{
        return "［基本剑法］入门剑法，能增加持剑时候的作战能力。每级提升1点剑的法术攻击力。\n";
}
