
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit NECK;

// ��������������
int get_family() { return 3; }

// ��������Ʒ���
int get_fin_type() { return 1301; }

// ���������촦��
void create()
{
        set_name("������");
        set_picid_1(8608);
        set_picid_2(8608);

        set_level(20);
        set_value(2500);
        set_max_lasting(5099);
        set("ap", 32);
        set("dp", 0);
        set("cp", 0);
        set("pp", 25);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "������";
}
