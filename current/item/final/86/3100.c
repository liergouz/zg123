
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit NECK;

// ��������������
int get_family() { return 3; }

// ��������Ʒ���
int get_fin_type() { return 1413; }

// ���������촦��
void create()
{
        set_name("¾������");
        set_picid_1(8612);
        set_picid_2(8612);

        set_level(100);
        set_value(20000);
        set_max_lasting(40099);
        set("ap", 127);
        set("dp", 0);
        set("cp", 0);
        set("pp", 108);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "¾������";
}
