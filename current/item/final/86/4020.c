
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit NECK;

// ��������������
int get_family() { return 4; }

// ��������Ʒ���
int get_fin_type() { return 1302; }

// ���������촦��
void create()
{
        set_name("������");
        set_picid_1(8608);
        set_picid_2(8608);

        set_level(20);
        set_value(2500);
        set_max_lasting(5099);
        set("ap", 24);
        set("dp", 0);
        set("cp", 0);
        set("pp", 30);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "������";
}
