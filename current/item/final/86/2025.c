
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit NECK;

// ��������������
int get_family() { return 2; }

// ��������Ʒ���
int get_fin_type() { return 1310; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(8612);
        set_picid_2(8612);

        set_level(25);
        set_value(5000);
        set_max_lasting(5599);
        set("ap", 36);
        set("dp", 0);
        set("cp", 55);
        set("pp", 43);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
