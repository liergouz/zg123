
// �Զ����ɣ�/make/npc/make8020
#include <ansi.h>
#include <npc.h>

#define INTERIOR_D      "/inh/city/interior"

inherit OFFICER;

// ��������ȡ��������
int get_char_picid() { return 0451; }

// ������ʦ��ʶ��
int is_master() { return 1; }

// ������ʦ��ʶ��(���ͷ)
int is_basic_master() { return 2; }

int is_self_look() { return 1; }

// ������С��ʶ��
int is_seller() { return 1; }

// ���������촦��
void create()
{
        set_name("��������");
        set_real_name("�÷�30~39");
        set_city_name("����");
	set_skill(0640, 39);
        set_2( "good", ([
                "01" : "/item/product/64025",
                "02" : "/item/product/64026",
                "03" : "/item/product/64027",
                "04" : "/item/product/64028",
                "05" : "/item/product/64029",
                "06" : "/item/product/64030",
                "07" : "/item/product/64031",
                "08" : "/item/product/64032",
                "09" : "/item/product/64033",
                "10" : "/item/product/64034",
                "11" : "/item/product/64035",        
                "12" : "/item/product/64036",
                "13" : "/item/product/64037",
                "14" : "/item/product/64038",
                "15" : "/item/product/64039",      
                "16" : "/item/product/64040",
                "17" : "/item/product/64041",
                "18" : "/item/product/64042",
                "19" : "/item/product/64043",
                "20" : "/item/product/64044",
                "21" : "/item/product/64045",        
                "22" : "/item/product/64046",
                "23" : "/item/product/64047",                                       
        ]) );		
        setup();
}

void do_look( object who )
{
        object me = this_object();
        send_user( who, "%c%c%w%s", ':', 3, 0451, 
        	sprintf("%s��\n    %s\n" 
	       	ESC "ѧϰ����\nlearn ? %s\n" 
	       	ESC "����÷켼�ܵȼ�30-39�����䷽\nlist %s\n"
        	ESC "�ر�\nCLOSE\n", 
        	me->get_name(), "/quest/word"->get_country_word(this_object()), me->get_char_id(), me->get_char_id() ) );
}

int accept_object( object who, object obj ) { return INTERIOR_D->accept_object_2( who, this_object(), obj, 2 ); }
