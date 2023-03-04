#pragma once

#include "Blackbird/Core/Core.h"

namespace Blackbird
{
    template <typename ObjectVertexType, std::size_t VERTICIES_PER_OBJECT, std::size_t INDICIES_PER_OBJECT>
    class BatchBuffer2D
    {
	public:
        BatchBuffer2D(std::size_t maxCount)
        {
            ResizeAndReset(maxCount);
        }

	public:
		static constexpr std::size_t GetVerticiesPerObject()    { return VERTICIES_PER_OBJECT; }
		static constexpr std::size_t GetIndiciesPerObject()     { return INDICIES_PER_OBJECT; }

		std::size_t GetMaxCount() const { return m_MaxCount; }
		std::size_t GetMaxIndicies() const { return m_MaxCount * INDICIES_PER_OBJECT; }
		std::size_t GetMaxVerticies() const { return m_MaxCount * VERTICIES_PER_OBJECT; }

		const ObjectVertexType* GetData() const     { return m_VerticiesBuffer.get(); }

		std::size_t GetObjectCount() const          { return m_ObjectCount; }
		std::size_t GetIndiciesCount() const        { return m_ObjectCount * INDICIES_PER_OBJECT; }
        std::size_t GetVerticiesSize() const        { return GetVerticieCount() * sizeof(ObjectVertexType); }

		std::size_t GetVerticieCount() const
        {
            BLACKBIRD_ASSERT((m_VerticiesBufferCurrentPos - m_VerticiesBuffer.get()) == (m_ObjectCount * VERTICIES_PER_OBJECT), "Wrong number of verticies compared to the number of objects")
            return m_ObjectCount * VERTICIES_PER_OBJECT;
        }

	public:
		void Reset()
        {
			m_VerticiesBufferCurrentPos = m_VerticiesBuffer.get();
            m_ObjectCount = 0;
		}

	public:
		bool CanPushBackVertex()                  { return m_VerticiesBufferCurrentPos < m_VerticiesBufferEnd; }
		bool CanPushBackVerticies(std::size_t count) { return m_VerticiesBufferCurrentPos + (count - 1) < m_VerticiesBufferEnd; }

		bool CanAddObject()
        {
            return CanPushBackVerticies(VERTICIES_PER_OBJECT) && m_ObjectCount < m_MaxCount;
		}

		void ObjectAdded()
        {
			BLACKBIRD_ASSERT(m_ObjectCount < m_MaxCount, "Wasn't able to add an Object in the BatchBuffer, manager must have been Flush")
			m_ObjectCount++;
        }

		void PushBackVertex(const ObjectVertexType& object)
        {
            BLACKBIRD_ASSERT(CanPushBackVertex(), "Wasn't able to add a Verex in the BatchBuffer, manager must have been Flush")
            *m_VerticiesBufferCurrentPos++ = object;
        }

    protected:
		void ResizeAndReset(std::size_t maxCount)
        {
            m_MaxCount = maxCount;
            m_VerticiesBuffer.reset(new ObjectVertexType[GetMaxVerticies()]);
            m_VerticiesBufferEnd = m_VerticiesBuffer.get() + GetMaxVerticies();
            m_VerticiesBufferCurrentPos = m_VerticiesBuffer.get();
        }

    protected:
		std::size_t m_MaxCount = 0;
		
        std::size_t m_ObjectCount = 0;

        std::unique_ptr<ObjectVertexType[]> m_VerticiesBuffer = nullptr;
		ObjectVertexType* m_VerticiesBufferEnd = nullptr;
		ObjectVertexType* m_VerticiesBufferCurrentPos = nullptr;
    };
}
