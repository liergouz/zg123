
// �Զ����ɣ�/make/npc/make-biao

#include <npc.h>
#include <ansi.h>

inherit OFFICER;

void do_task_start();
void do_task_cancel();

// ��������ȡ��������
int get_char_picid() { return 7301; }

int is_self_look() { return 1; }

// ������С��ʶ��
int is_seller() { return 1; }

// ���������촦��
void create()
{
        set_name("������");
        set_real_name("�÷�59~68");
        set_city_name("����");

/*      set_2( "talk", ([
                "task"          : (: do_task_start :),
                "cancel"        : (: do_task_cancel :),
        ]));    */
        set_2( "good", ([
                "01" : "/item/product/64092",
                "02" : "/item/product/64093",
                "03" : "/item/product/64094",
                "04" : "/item/product/64095",
                "05" : "/item/product/64096",
                "06" : "/item/product/64097",
                "07" : "/item/product/64098",
                "08" : "/item/product/64099",
                "09" : "/item/product/64100",
                "10" : "/item/product/64101",
                "11" : "/item/product/64102",        
                "12" : "/item/product/64103",
                "13" : "/item/product/64104",
                "14" : "/item/product/64105",
                "15" : "/item/product/64106",      
                "16" : "/item/product/64107",
                "17" : "/item/product/64108",
                "18" : "/item/product/64109",
                "19" : "/item/product/64110",
                "20" : "/item/product/64111",
                "21" : "/item/product/64112",        
                "22" : "/item/product/64113",
                "23" : "/item/product/64114",                                       
                "24" : "/item/product/64115",
        ]) );
        setup();
}

void do_look( object who ) 
{ 
	TASK_ESCORT_D->do_look_2( who, this_object() ); 
}

// ��������ʼ����
// void do_task_start() { TASK_ESCORT_D->do_task_start( this_player(), this_object() ); }
// ������ȡ������
// void do_task_cancel() { TASK_ESCORT_D->do_task_cancel( this_player(), this_object() ); }
