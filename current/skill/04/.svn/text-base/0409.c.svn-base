
inherit SKILL;

// 函数：基本技能
int is_basic_skill() { return 1; }

// 函数：构造处理
void create() 
{ 
        set_number(0409);
        set_name( "神游" );
}

// 函数：能否特殊技
void can_perform( object me )
{
        __DIR__ "04091"->can_perform(me);
}

// 函数：删除特殊技
void remove_perform( object me )
{
        send_user( me, "%c%w%w", 0x50, 0xffff, 04091 );
}

// 函数：获取描述
string get_desc() 
{
        return "［神游］快速移动到其他人身边，对方法力越低成功率越高\n";
}
