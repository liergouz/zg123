
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit NECK;

// ��������������
int get_family() { return 1; }

// ��������Ʒ���
int get_fin_type() { return 1419; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(8655);
        set_picid_2(8655);

        set_level(105);
        set_value(20000);
        set_max_lasting(45099);
        set("ap", 131);
        set("dp", 0);
        set("cp", 0);
        set("pp", 109);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
