
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit NECK;

// ��������������
int get_family() { return 3; }

// ��������Ʒ���
int get_fin_type() { return 1329; }

// ���������촦��
void create()
{
        set_name("�¹�����");
        set_picid_1(8612);
        set_picid_2(8612);

        set_level(40);
        set_value(20000);
        set_max_lasting(7099);
        set("ap", 56);
        set("dp", 0);
        set("cp", 0);
        set("pp", 45);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "�¹�����";
}
