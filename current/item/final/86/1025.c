
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit NECK;

// ��������������
int get_family() { return 1; }

// ��������Ʒ���
int get_fin_type() { return 1307; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(8612);
        set_picid_2(8612);

        set_level(25);
        set_value(5000);
        set_max_lasting(5599);
        set("ap", 35);
        set("dp", 0);
        set("cp", 0);
        set("pp", 29);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
