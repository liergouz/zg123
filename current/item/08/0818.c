// make/item/make_ss_item����

#include <item.h>
#include <ansi.h>
inherit ITEM;
inherit USABLE;
int get_item_value() {return 450 ;}
int get_item_value_2() {return 450 ;}
int get_item_number() {return 10001080 ;}   
int get_item_color() { return 2;};
// ���������촦��
void create()
{
        set_name("ʨ��");
        set_picid_1(3025);
        set_picid_2(4264);
        set("picid",3025);
        set_value(888);
        set_no_give(1);
}

// ��������ȡ����
string get_desc() 
{
	return "ʮ������֮һ��ʨ����";
}
// ������ʹ��Ч��
int get_use_effect( object me )
{
	send_user( me, "%c%c%w%s", ':', 3, 0,sprintf("ʹ�ú󽫻������ޣ��Ƿ�ʹ�ã�\n"ESC"ȷ��\nuse ! %x#\n"ESC"ȡ��",getoid(this_object()))); 
	return 0;
}
// ������ʹ��Ч��
int confirm_use( object me ) 
{ 
	return "sys/user/beast"->use_shenshou_item(me,this_object());
}
