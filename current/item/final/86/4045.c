
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit NECK;

// ��������������
int get_family() { return 4; }

// ��������Ʒ���
int get_fin_type() { return 1337; }

// ���������촦��
void create()
{
        set_name("ˮ������");
        set_picid_1(8655);
        set_picid_2(8655);

        set_level(45);
        set_value(20000);
        set_max_lasting(7599);
        set("ap", 54);
        set("dp", 0);
        set("cp", 0);
        set("pp", 55);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "ˮ������";
}
